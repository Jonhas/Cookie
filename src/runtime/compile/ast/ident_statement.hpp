#ifndef IDENT_STATEMENT_HPP
#define IDENT_STATEMENT_HPP

#include "identifier.hpp"
#include "statement.hpp"

namespace cookie {
/*
 *
 */
template <typename T> class ident_statement : public cookie::statement<T> {
public:
  std::unique_ptr<cookie::identifier<T>> iden;
  std::unique_ptr<cookie::expression<T>> value;

  cookie::statement<T> statementNode() {}
  inline std::string token_literal() { return name->tok.value; }
};
} // namespace cookie

#endif