#ifndef IDENTIFIER_EXPRESSION_HPP
#define IDENTIFIER_EXPRESSION_HPP
#include "expression.hpp"

namespace cookie {
/*
 *  Identifier node to express an identifier
 *  identifier := <letter>{0-9}*{_}*
 */
template <typename T>
class identifier_expression : public cookie::expression<T> {
public:
  explicit identifier_expression(const cookie::token &t) : tok(std::move(t)) {
    assert(tok.type == cookie::token_type::token_identifier);
  }
  inline std::string expressionNode() override {
    return std::string("Identifier node with ") + tok.value;
  }
  cookie::token tok;
};
} // namespace cookie

#endif
