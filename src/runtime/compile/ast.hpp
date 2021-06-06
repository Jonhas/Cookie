#ifndef AST_HPP
#define AST_HPP
#include "compile.hpp"
#include <type_traits>
namespace cookie {

class node {
public:
  virtual std::string token_literal() { return "generic node"; }
};

class statement {
public:
  virtual std::string statement_literal() { return "generic statement node\n"; }
};

class expression {
public:
  virtual std::string expression_literal() {
    return "generic expression node\n";
  }
};

/*
 *  Identifier node to express an identifiier
 *  <ident_expression> ::= <letter>{0-9}*{_}*
 */
template <typename T> class ident_expression : public cookie::expression {
public:
  explicit ident_expression(const cookie::token &tok) : tok(std::move(tok)) {}
  std::string expression_literal() override {
    return "identifier expression node with " + tok.value;
  }
  cookie::token tok;
};

/*
 *  <ident_statement> ::= <ident_expression> <expression>
 */
template<typename T>
class ident_statement : public cookie::statement
{
public:
  std::string statement_literal() override 
  {
    return "Generic statement node with identifier " + iden->tok.value; 
  }

  std::unique_ptr<cookie::ident_expression<T>> iden; 
  std::unique_ptr<cookie::expression> expr; 
}; 

} // namespace cookie

#endif
