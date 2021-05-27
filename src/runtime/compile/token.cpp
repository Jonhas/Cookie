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
  case '+':
    return token_type::token_add;
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
  case ':':
    return token_type::token_init;
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
