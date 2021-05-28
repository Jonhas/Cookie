#ifndef AST_HPP
#define AST_HPP

#include "../compile.hpp"

namespace cookie {
/*
 * Generic Node class, an item within an AST
 */
template <typename T> class node {
public:
  inline virtual std::string token_literal() {return std::string("Generic AST Node");}
};

} // namespace cookie
#endif
