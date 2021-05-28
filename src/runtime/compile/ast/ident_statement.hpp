#ifndef IDENT_STATEMENT_HPP
#define IDENT_STATEMENT_HPP

#include "identifier_expression.hpp"
#include "statement.hpp"

namespace cookie {
/*
 *
 */
template <typename T> class ident_statement : public cookie::statement<T> {
public:
  std::unique_ptr<cookie::identifier_expression<T>> iden;
  std::unique_ptr<cookie::expression<T>> value;

  inline std::string statementNode() override {
    return std::string("Generic statement node with identifier") + iden->tok.value ; 
  }
};
} // namespace cookie

#endif