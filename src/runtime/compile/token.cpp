#include "token.hpp"

cookie::token_type cookie::token::token_oneChar(int c1) {
  switch (c1) {
  case '%':
    return token_type::token_mod;
  case '(':
    return token_type::token_lparen;
  case ')':
    return token_type::token_rparen;
  case '[':
    return token_type::token_lbrack;
  case ']':
    return token_type::token_rbrack;
  case '{':
    return token_type::token_lbrace;
  case '}':
    return token_type::token_rbrace;
  case '*':
    return token_type::token_mult;
  case '-':
    return token_type::token_sub;
  case '/':
    return token_type::token_divis;
  case ';':
    return token_type::token_semicolon;
  case '<':
    return token_type::token_less;
  case '>':
    return token_type::token_greater;
  case '.':
    return token_type::token_dot;
  }
  return token_type::token_error;
}

cookie::token_type cookie::token::token_twoChars(int c1, int c2) {
  switch (c1) {
  case '*':
    switch (c2) {
    case '=':
      return token_type::token_mult_equal;
    case '*':
      return token_type::token_exp;
    }
    break;
  case '/':
    switch (c2) {
    case '=':
      return token_type::token_divis_equal;
    }
    break;
  case '%':
    switch (c2) {
    case '=':
      return token_type::token_mod_equal;
    }
    break;
  case '+':
    switch (c2) {
    case '+':
      return token_type::token_increm;
    case '=':
      return token_type::token_add_equal;
    }
    break;
  case '-':
    switch (c2) {
    case '-':
      return token_type::token_decrem;
    case '=':
      return token_type::token_sub_equal;
    }
    break;
  case '<':
    switch (c2) {
    case '=':
      return token_type::token_lessEqual;
    }
    break;
  case '>':
    switch (c2) {
    case '=':
      return token_type::token_greaterEqual;
    }
    break;
  case '=':
    switch (c2) {
    case '=':
      return token_type::token_equal;
    case '>':
      return token_type::token_arrow;
    }
    break;
  case ':':
    switch (c2) {
    case '=':
      return token_type::token_assign;
    }
    break;
  }
  return token_type::token_error;
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

constexpr bool cookie::token::is_deliometer(int c1) {
  return ((c1 == '(') || (c1 == ')') || (c1 == '{') || (c1 == '}') ||
          (c1 == '[') || (c1 == ']'));
}

constexpr bool cookie::token::is_arithmetic_operator(int c1) {
  return ((c1 == '+') || (c1 == '-') || (c1 == '*') || (c1 == '/') ||
          (c1 == '%'));
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