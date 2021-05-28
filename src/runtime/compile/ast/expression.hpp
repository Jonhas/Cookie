#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "node.hpp"
#include <cassert>
namespace cookie {
/*
 * Expression node to handle the production of values
 */
template <typename T> class expression : public cookie::node<T> {
public:
  inline virtual std::string expressionNode(){
    return "generic expression Node\n";
    }
};

} // namespace cookie

#endif