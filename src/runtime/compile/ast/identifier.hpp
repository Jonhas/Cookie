#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include "expression.hpp"

namespace cookie {

template <typename T> class identifier : public cookie::expression<T> {
public:
  explicit identifier(const cookie::token &t) : tok(std::move(t)) {}
  inline std::string token_literal() { return tok.value; }
  cookie::expression<T> expressionNode() {}
  cookie::token tok;
};
} // namespace cookie

#endif