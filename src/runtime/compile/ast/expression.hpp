#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "node.hpp"
#include <cassert>
namespace cookie {
/*
 * Expression node to handle the production of values
 */
template <typename T> class expression : public cookie::Node<T> {
public:
  inline std::string expressionNode();
  inline std::string token_literal();
};

} // namespace cookie

#endif