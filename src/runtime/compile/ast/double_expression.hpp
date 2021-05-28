#ifndef DOUBLE_LITERAL_HPP
#define DOUBLE_LITERAL_HPP

#include "expression.hpp"

namespace cookie {
template <typename T> class double_expression : public cookie::expression<T> {
public:
  explicit double_expression(const cookie::token &token)
      : tok(std::move(token)) {
    assert(tok.type == cookie::token_type::token_double);
  }

  inline std::string expressionNode() override {
    return std::string("Double literal node with value ") + tok.value;
  }
  cookie::token tok;
};
} // namespace cookie

#endif