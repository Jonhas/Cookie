#ifndef AUG_OPERATOR_HPP
#define AUG_OPERATOR_HPP

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
template <typename T> class aug_operator : public cookie::expression<T> {
  explicit aug_operator(const cookie::token &val) noexcept
      : val(std::move(val)) {}
  cookie::expression<T> expressionNode(){}
  cookie::token val;
};
} // namespace cookie

#endif