#include "lexer.hpp"

std::unique_ptr<cookie::token> cookie::lexer::tokenize() {
  while (1) {
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
  }
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
  if ((peek(1) == '=') || (peek(1) == peek())) {
    auto type = cookie::token::token_twoChars(peek(), peek(1));
    auto temp = std::string(1, peek()) + peek(1);
    lexer_advance(2);
    return std::make_unique<cookie::token>(type, temp);
  }
  lexer_advance();
  std::string temp(1, peek());
  auto type = cookie::token::token_oneChar(peek());
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