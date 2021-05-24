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

  token(token_type type, const std::string &value)
      : type(type), value(std::move(value)) {}

  token(const token &other) = default;
  token &operator=(const token &other) = default;

  static token_type token_oneChar(int c1);
  static token_type token_twoChars(int c1, int c2);

  static constexpr bool is_whitespace(int c1);
  static constexpr bool is_delimeter(int c1);
  static constexpr bool is_arithmetic_operator(int c1);
  static constexpr bool is_comparison_operator(int c1);
  static constexpr bool is_alpha_or_numeric(int c1);
  static constexpr bool is_alpha(int c1);
  static constexpr bool is_digit(int c1);
  static constexpr bool is_ascii(int c1);
  static constexpr int string_to_int(char *ptr);

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

  token_type type{};
  std::string value{};
};

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
