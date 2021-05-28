#ifndef INT_LITERAL_HPP
#define INT_LITERAL_HPP

#include "expression.hpp"

namespace cookie {
template <typename T> class int_literal : public cookie::expression<T> {
public:
  explicit int_literal(const cookie::token &tok) : token(std::move(tok)) {
    assert(token.type == cookie::token_type::token_int);
  }
  cookie::token token;
};
} // namespace cookie

#endif