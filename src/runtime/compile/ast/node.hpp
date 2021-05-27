#ifndef AST_HPP
#define AST_HPP

#include "../compile.hpp"

namespace cookie {
/*
 * Generic Node class, an item within an AST
 */
template <typename T> class Node {
public:
  inline std::string token_literal();
};

} // namespace cookie
#endif