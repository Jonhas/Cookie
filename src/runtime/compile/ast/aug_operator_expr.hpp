#ifndef AUG_OPERATOR_EXPR_HPP
#define AUG_OPERATOR_EXPR_HPP

#include "expression.hpp"
namespace cookie {

/*
 *  Node to represent an augmented assignment operator.
 *  aug_operator := "**="
 *      | "//="
 *      | "+="
 *      | "-="
 *      | "*="
 *      | "/="
 *      | "%="
 */
template <typename T> class aug_operator_expr : public cookie::expression<T> {
  explicit aug_operator_expr(const cookie::token &val) noexcept
      : tok(std::move(val)) {}
  inline std::string expressionNode() override {
    return std::string("aug operator with value ") + tok.value;
  }
  cookie::token tok;
};
} // namespace cookie

#endif