#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP
#include "expression.hpp"

namespace cookie {
/*
 *  Identifier node to express an identifier
 *  identifier := <letter>{0-9}*{_}*
 */
template <typename T> class identifier : public cookie::expression<T> {
public:
  explicit identifier(const cookie::token &t) : tok(std::move(t)) {
    assert(tok.type == cookie::token_type::token_identifier);
  }
  inline std::string token_literal() { return tok.value; }
  cookie::expression<T> expressionNode() {}
  cookie::token tok;
};
} // namespace cookie

#endif
