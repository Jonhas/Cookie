#ifndef INT_EXPRESSION_HPP
#define INT_EXPRESSION_HPP

#include "expression.hpp"

namespace cookie {
template <typename T> class int_expression : public cookie::expression<T> {
public:
  explicit int_expression(const cookie::token &tok) : tok(std::move(tok)) {
    assert(tok.type == cookie::token_type::token_int);
  }
  inline std::string expressionNode() override {
    return std::string("int literal token with value ") + tok.value;
  }
  cookie::token tok;
};
} // namespace cookie

#endif