#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <unordered_map>

namespace cookie {
enum class token_type {
  token_void = 0,
  token_function,

  token_return,
  token_semicolon,

  token_int,
  token_bool,
  token_string,
  token_double,
  token_char,

  token_identifier,
  token_struct,

  token_spec_int,
  token_spec_double,
  token_spec_bool,
  token_spec_string,
  token_spec_char,
  token_spec_struct,

  token_if,
  token_elif,
  token_else,
  token_for,
  token_while,
  token_break,
  token_continue,
  token_arrow,
  token_const,

  token_dot,
  token_comma,

  token_assign,
  token_init,

  token_equal,
  token_neq,
  token_less,
  token_lessEqual,
  token_greater,
  token_greaterEqual,

  token_add,
  token_sub,
  token_mult,
  token_exp,
  token_divis,
  token_increm,
  token_decrem,
  token_mod,
  token_add_equal,
  token_sub_equal,
  token_mult_equal,
  token_divis_equal,
  token_mod_equal,
  token_exp_equal,

  token_true,
  token_false,
  token_not,
  token_and,
  token_or,
  token_xor,
  token_nand,

  token_nil,

  token_type,
  token_use,
  token_as,

  token_lparen,
  token_rparen,
  token_lbrack,
  token_rbrack,
  token_lbrace,
  token_rbrace,

  token_eof,
  token_error
};

class token final {
public:
  explicit token(token_type type) : type(type), value() {}
  explicit token(const token &t)
      : type(std::move(t.type)), value(std::move(t.value)) {}

  token(token_type type, std::string value)
      : type(type), value(std::move(value)) {}

  static token_type token_oneChar(int c1);
  static token_type token_twoChars(int c1, int c2);
  static token_type token_threeChars(int c1, int c2, int c3);
  static constexpr bool is_whitespace(int c1);
  static constexpr bool is_delimeter(int c1);
  static constexpr bool is_arithmetic_operator(int c1);
  static constexpr bool is_comparison_operator(int c1);
  static constexpr bool is_alpha_or_numeric(int c1);
  static constexpr bool is_alpha(int c1);
  static constexpr bool is_digit(int c1);
  static constexpr bool is_ascii(int c1);
  static constexpr int string_to_int(char *ptr);
  friend inline std::ostream &operator<<(std::ostream &os, token_type type);
  static inline const std::unordered_map<std::string, token_type> keywords = {
      {"void", token_type::token_void},
      {"fn", token_type::token_function},
      {"return", token_type::token_return},
      {"int", token_type::token_spec_int},
      {"double", token_type::token_spec_double},
      {"bool", token_type::token_spec_bool},
      {"true", token_type::token_true},
      {"false", token_type::token_false},
      {"and", token_type::token_and},
      {"or", token_type::token_or},
      {"xor", token_type::token_xor},
      {"nand", token_type::token_nand},
      {"not", token_type::token_not},
      {"neq", token_type::token_neq},
      {"string", token_type::token_spec_string},
      {"struct", token_type::token_spec_struct},
      {"if", token_type::token_if},
      {"elif", token_type::token_elif},
      {"else", token_type::token_else},
      {"for", token_type::token_for},
      {"while", token_type::token_while},
      {"break", token_type::token_break},
      {"continue", token_type::token_continue},
      {"const", token_type::token_const},
      {"nil", token_type::token_nil},
      {"type", token_type::token_type},
      {"use", token_type::token_use},
      {"as", token_type::token_as}};

  bool operator==(token &&other) {
    return (type == std::move(other.type)) && (value == std::move(other.value));
  }

  token &operator=(token &&other) {
    if (this == &other)
      return *this;
    type = std::move(other.type);
    value = std::move(other.value);
  }

  token &operator=(const token &other) {
    if (this == &other)
      return *this;

    type = other.type;
    value = other.value;
    return *this;
  }

  token_type type{};
  std::string value{};
};

std::ostream &operator<<(std::ostream &os, cookie::token_type type) {
  switch (type) {
  case cookie::token_type::token_void:
    os << "void";
    break;
  case cookie::token_type::token_function:
    os << "fn token";
    break;
  case cookie::token_type::token_return:
    os << "return token";
    break;
  case cookie::token_type::token_semicolon:
    os << "semicolon token";
    break;
  case cookie::token_type::token_int:
    os << "int literal";
    break;
  case cookie::token_type::token_bool:
    os << "bool literal";
    break;
  case cookie::token_type::token_string:
    os << "string literal";
    break;
  case cookie::token_type::token_double:
    os << "double literal";
    break;
  case cookie::token_type::token_char:
    os << "char literal";
    break;
  case cookie::token_type::token_identifier:
    os << "identifier token";
    break;
  case cookie::token_type::token_struct:
    os << "struct token";
    break;
  case cookie::token_type::token_spec_bool:
    os << "bool specifier";
    break;
  case cookie::token_type::token_spec_char:
    os << "char specifier";
    break;
  case cookie::token_type::token_spec_double:
    os << "double specifier";
    break;
  case cookie::token_type::token_spec_int:
    os << "int specifier";
    break;
  case cookie::token_type::token_spec_string:
    os << "string specifier";
    break;
  case cookie::token_type::token_spec_struct:
    os << "struct specifier";
    break;
  case cookie::token_type::token_if:
    os << "if token";
    break;
  case cookie::token_type::token_elif:
    os << "elif token";
    break;
  case cookie::token_type::token_else:
    os << "else token";
    break;
  case cookie::token_type::token_for:
    os << "for token";
    break;
  case cookie::token_type::token_while:
    os << "while token";
    break;
  case cookie::token_type::token_break:
    os << "break token";
    break;
  case cookie::token_type::token_continue:
    os << "continue token";
    break;
  case cookie::token_type::token_arrow:
    os << "=> token";
    break;
  case cookie::token_type::token_const:
    os << "const";
    break;
  case cookie::token_type::token_dot:
    os << ". token";
    break;
  case cookie::token_type::token_comma:
    os << ", token";
    break;
  case cookie::token_type::token_assign:
    os << ":= token";
    break;
  case cookie::token_type::token_neq:
    os << "neq";
    break;
  case cookie::token_type::token_less:
    os << "< token";
    break;
  case cookie::token_type::token_lessEqual:
    os << "<= token";
    break;
  case cookie::token_type::token_greater:
    os << "> token";
    break;
  case cookie::token_type::token_greaterEqual:
    os << ">= token";
    break;
  case cookie::token_type::token_add:
    os << "+ token";
    break;
  case cookie::token_type::token_sub:
    os << "- token";
    break;
  case cookie::token_type::token_mult:
    os << "* token";
    break;
  case cookie::token_type::token_exp:
    os << "** token";
    break;
  case cookie::token_type::token_divis:
    os << "/ token";
    break;
  case cookie::token_type::token_increm:
    os << "++ token";
    break;
  case cookie::token_type::token_decrem:
    os << "-- token";
    break;
  case cookie::token_type::token_mod:
    os << "% token";
    break;
  case cookie::token_type::token_add_equal:
    os << "+= token";
    break;
  case cookie::token_type::token_sub_equal:
    os << "-= token";
    break;
  case cookie::token_type::token_mult_equal:
    os << "*= token";
    break;
  case cookie::token_type::token_divis_equal:
    os << "/= token";
    break;
  case cookie::token_type::token_mod_equal:
    os << "%= token";
    break;
  case cookie::token_type::token_true:
    os << "true literal";
    break;
  case cookie::token_type::token_false:
    os << "false literal";
    break;
  case cookie::token_type::token_not:
    os << "not token";
    break;
  case cookie::token_type::token_and:
    os << "and token";
    break;
  case cookie::token_type::token_or:
    os << "or token";
    break;
  case cookie::token_type::token_xor:
    os << "xor token";
    break;
  case cookie::token_type::token_nand:
    os << "nand token";
    break;
  case cookie::token_type::token_nil:
    os << "nil token";
    break;
  case cookie::token_type::token_type:
    os << "type token";
    break;
  case cookie::token_type::token_use:
    os << "use token";
    break;
  case cookie::token_type::token_as:
    os << "as token";
    break;
  case cookie::token_type::token_lparen:
    os << "( token";
    break;
  case cookie::token_type::token_rparen:
    os << ") token";
    break;
  case cookie::token_type::token_lbrack:
    os << "[ token";
    break;
  case cookie::token_type::token_rbrack:
    os << "] token";
    break;
  case cookie::token_type::token_lbrace:
    os << "{ token";
    break;
  case cookie::token_type::token_rbrace:
    os << "} token";
    break;
  case cookie::token_type::token_eof:
    os << "eof token";
    break;
  case cookie::token_type::token_error:
    os << "ERROR";
    break;
  // case token_type::token
  default:
    break;
  }
  return os;
}

constexpr bool cookie::token::is_alpha(int c1) {
  return (c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z');
}

constexpr bool cookie::token::is_digit(int c1) {
  return (c1 >= '0' && c1 <= '9');
}

constexpr bool cookie::token::is_alpha_or_numeric(int c1) {
  return cookie::token::is_alpha(c1) || cookie::token::is_digit(c1);
}

constexpr bool cookie::token::is_whitespace(int c1) {
  return (c1 == ' ' || c1 == 10 || c1 == '\t' || c1 == '\f' || c1 == '\r' ||
          c1 == '\v');
}

constexpr bool cookie::token::is_delimeter(int c1) {
  return ((c1 == '(') || (c1 == ')') || (c1 == '{') || (c1 == '}') ||
          (c1 == '[') || (c1 == ']'));
}

constexpr bool cookie::token::is_comparison_operator(int c1) {
  return ((c1 == '<') || (c1 == '>'));
}

constexpr bool cookie::token::is_ascii(int c1) {
  return !(c1 >= 0 && c1 < 128);
}

constexpr int cookie::token::string_to_int(char *ptr) {
  int x = 0;
  bool neg = false;
  if (*ptr == '-') {
    neg = true;
    ++ptr;
  }
  while (*ptr != '\0') {
    x = (x * 10) + (*ptr - '0');
    ++ptr;
  }
  if (neg)
    x = -x;
  return x;
}

constexpr bool cookie::token::is_arithmetic_operator(int c1) {
  return ((c1 == '+') || (c1 == '-') || (c1 == '*') || (c1 == '/') ||
          (c1 == '%'));
}

} // namespace cookie

#endif
