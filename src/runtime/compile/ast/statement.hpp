#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "node.hpp"

namespace cookie {
/*
 * Statement node to express the instantiation of statements in a program.
 */
template <typename T> class statement : public cookie::node<T> {
public:
  inline virtual std::string statementNode() {
    return std::string("Generic statement node");
  }
  inline std::string token_literal();
};

} // namespace cookie

#endif
