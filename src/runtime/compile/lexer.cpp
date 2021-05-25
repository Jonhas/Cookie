#include "lexer.hpp"

std::unique_ptr<cookie::token> cookie::lexer::tokenize() {
  while (true) {
    if (check_eof())
      return std::make_unique<cookie::token>(token_type::token_eof, "EOF");
    if (cookie::token::is_whitespace(peek())) {
      while (cookie::token::is_whitespace(peek()))
        lexer_advance();
    }
    if (cookie::token::is_arithmetic_operator(peek()))
      return evaluate_arithmetic_and_advance();
    if (cookie::token::is_comparison_operator(peek()))
      return evaluate_comparison_and_advance();
    if (cookie::token::is_delimeter(peek()))
      return evaluate_delimeters_and_advance();
    if (cookie::token::is_digit(peek()))
      return evaluate_numbers_and_advance();
    if (peek() == '\'')
      return evaluate_char_and_advance();
    if (peek() == '\"')
      return evaluate_string_and_advance();
    if (cookie::token::is_alpha(peek()))
      return evaluate_keywords_or_identifiers();
    if (peek()==','){
      lexer_advance(); 
      return std::make_unique<cookie::token>(token_type::token_comma,","); 
    }
    if (peek() == '.') {
      lexer_advance();
      return std::make_unique<cookie::token>(token_type::token_dot, ".");
    }
    if(peek() == ':')  {
      if (peek(1)=='=') {
        lexer_advance(2); 
        return std::make_unique<cookie::token>(token_type::token_assign, ":="); 
      }
      else{
        lexer_advance(); 
        return std::make_unique<cookie::token>(token_type::token_init, ":"); 
      } 
    }
    if (peek()=='='){
      if (peek(1)=='>'){
        lexer_advance(2); 
        return std::make_unique<cookie::token>(token_type::token_arrow, "=>"); 
      }
      else if (peek(1)=='='){
        lexer_advance(2); 
        return std::make_unique<cookie::token>(token_type::token_equal, "=="); 
      }
    }
    if (peek() == ';') {
      lexer_advance();
      return std::make_unique<cookie::token>(token_type::token_semicolon, ";");
    }
  }
}

std::unique_ptr<cookie::token>
cookie::lexer::evaluate_keywords_or_identifiers() {
  std::string temp;
  while (cookie::token::is_alpha_or_numeric(peek())) {
    temp += peek();
    lexer_advance();
    if (peek() == '_') {
      temp += peek();
      lexer_advance();
    }
  }
  const auto got = cookie::token::keywords.find(temp);
  if (got != cookie::token::keywords.end())
    return std::make_unique<token>(got->second, temp);
  else
    return std::make_unique<token>(token_type::token_identifier, temp);
}

std::unique_ptr<cookie::token> cookie::lexer::evaluate_string_and_advance() {
  // eat the " char
  lexer_advance();
  std::string temp;
  while (peek() != '\"') {
    temp += peek();
    lexer_advance();
    if (check_eof())
      return std::make_unique<cookie::token>(token_type::token_error,
                                             "eof while tokenizing string");
  }

  // eat the closing " char
  lexer_advance();
  return std::make_unique<cookie::token>(token_type::token_string, temp);
}

std::unique_ptr<cookie::token> cookie::lexer::evaluate_char_and_advance() {
  lexer_advance();
  auto temp = std::string(1, peek());
  lexer_advance();
  if (peek() != '\'')
    return std::make_unique<cookie::token>(token_type::token_error,
                                           "Invalid char");
  lexer_advance();
  return std::make_unique<cookie::token>(token_type::token_char, temp);
}

std::unique_ptr<cookie::token> cookie::lexer::evaluate_numbers_and_advance() {
  std::string temp;
  while (cookie::token::is_digit(peek())) {
    temp += peek();
    lexer_advance();
    if (peek() == '.') {
      temp += peek();
      lexer_advance();
      while (cookie::token::is_digit(peek())) {
        temp += peek();
        lexer_advance();
      }
      return std::make_unique<cookie::token>(token_type::token_double, temp);
    }
  }
  return std::make_unique<cookie::token>(token_type::token_int, temp);
}

std::unique_ptr<cookie::token>
cookie::lexer::evaluate_arithmetic_and_advance() {
  if ((peek(1) == '=') || (peek()==peek(1))) {
    auto type = cookie::token::token_twoChars(peek(), peek(1));
    auto temp = std::string(1, peek()) + peek(1);
    lexer_advance(2);
    return std::make_unique<cookie::token>(type, temp);
  }
  std::string temp(1,peek());
  auto type = cookie::token::token_oneChar(peek());
  lexer_advance(); 
  return std::make_unique<cookie::token>(type, temp);
}

std::unique_ptr<cookie::token>
cookie::lexer::evaluate_comparison_and_advance() {
  if (peek(1) == '=') {
    auto type = cookie::token::token_twoChars(peek(), peek(1));
    auto temp = std::string(1, peek()) + peek(1);
    lexer_advance(2);
    return std::make_unique<cookie::token>(type, temp);
  }
  std::string temp(1, peek());
  auto type = cookie::token::token_oneChar(peek());
  lexer_advance();
  return std::make_unique<cookie::token>(type, temp);
}

std::unique_ptr<cookie::token>
cookie::lexer::evaluate_delimeters_and_advance() {
  auto type = cookie::token::token_oneChar(peek());
  std::string temp(1, peek());
  lexer_advance();
  return std::make_unique<cookie::token>(type, temp);
}

void cookie::lexer::lexer_advance(size_t amount) { position += amount; }

bool cookie::lexer::check_eof() const { return position > source.length() - 1; }

char cookie::lexer::peek(size_t following) const {
  if ((position + following) >= source.length())
    return '\0';
  return source[position + following];
}