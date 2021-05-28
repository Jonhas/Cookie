#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "node.hpp"

namespace cookie {

template <typename T> class statement : public cookie::Node<T> {
public:
  inline std::string statementNode();
  inline std::string token_literal();
  
};

} // namespace cookie

#endif
