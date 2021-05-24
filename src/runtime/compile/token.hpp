#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

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

  token_type token_oneChar(int c1);
  token_type token_twoChars(int c1, int c2);
  constexpr bool is_whitespace(int c1);
  constexpr bool is_deliometer(int c1);
  constexpr bool is_arithmetic_operator(int c1);
  constexpr bool is_comparison_operator(int c1);
  constexpr bool is_alpha_or_numeric(int c1);
  constexpr bool is_alpha(int c1);
  constexpr bool is_digit(int c1);
  constexpr bool is_ascii(int c1);
  constexpr int string_to_int(char *ptr);

  token_type type{};
  std::string value{};
};
} // namespace cookie

#endif
