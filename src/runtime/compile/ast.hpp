#ifndef AST_HPP
#define AST_HPP
#include "compile.hpp"
#include <cassert>
#include <type_traits>
namespace cookie {

class node {
public:
  virtual std::string token_literal() { return "generic node"; }
  virtual ~node() {}
};

class statement : public cookie::node {
public:
  virtual std::string statement_literal() { return "generic statement node\n"; }
};

class expression : public cookie::node {
public:
  virtual std::string expression_literal() {
    return "generic expression node\n";
  }
};

template <typename T> class program : public cookie::node {
public:
  explicit program(
      const std::vector<std::unique_ptr<cookie::statement>> &statements)
      : statements(std::move(statements)) {}

  std::string token_literal() override {
    if (statements.size() > 0)
      return statements[0]->token_literal();
    else
      return "empty statements";
  }
  std::vector<std::unique_ptr<cookie::statement>> statements;
};

/*
 *  Identifier node to express an identifiier
 *  <ident_node> ::= <letter>{0-9}*{_}*
 */
template <typename T> class ident_node : public cookie::expression {
public:
  explicit ident_node(const T &tok) : tok(std::move(tok)) {
    static_assert(std::is_same<T, cookie::token>::value,
                  "Must be a scoped token enum");
    assert(tok.type == cookie::token_type::token_identifier);
  }

  std::string token_literal() override {
    return "identifier expression node with " + tok.value;
  }
  T tok;
};

/*
 *  <ident_statement> ::= <ident_node> <expression>
 */
template <typename T> class ident_statement : public cookie::statement {
public:
  std::string statement_literal() override {
    return "Generic statement node with identifier " + iden->tok.value;
  }

  std::unique_ptr<cookie::ident_node<T>> iden;
  std::unique_ptr<cookie::expression> expr;
};

/*
 *  Node to represent an augmented assignment operator
 *  aug_operator := **=
 *    | //=
 *    | +=
 *    | -=
 *    | %=
 */
template <typename T> class aug_operator_node : public cookie::expression {
public:
  explicit aug_operator_node(const T &tok) : tok(std::move(tok)) {
    static_assert(std::is_same<T, cookie::token>::value,
                  "must be a scoped token enum");
  }

  std::string token_literal() override {
    return "aug operator with value " + tok.value;
  }
  T tok;
};

bool is_aug_op(const std::string c) {
  return (c == "//=") || (c == "**=") || (c == "+=") || (c == "-=") ||
         (c == "%=");
}
/*
 *  Double node to represent floating point numbers
 *  <double_node> ::= {0-9}+.{0-9}+
 */
template <typename T> class double_node : public cookie::expression {
public:
  explicit double_node(const T &tok) : tok(std::move(tok)) {
    static_assert(std::is_same<T, cookie::token>::value,
                  "must be a scoped token enum");
    assert(tok.type == cookie::token_type::token_double);
  }

  std::string token_literal() override {
    return "double literal node with value " + tok.value;
  }
  T tok;
};

/*
 *  int node to represent integers
 *  <int_node> ::= {0-9}+
 */
template <typename T> class int_node : public cookie::expression {
public:
  explicit int_node(const T &tok) : tok(std::move(tok)) {
    static_assert(std::is_same<T, cookie::token>::value,
                  "type must be a scoped token enum");
    assert(tok.type == cookie::token_type::token_int);
  }

  std::string token_literal() override {
    return "int node with value " + tok.value;
  }
  T tok;
};

} // namespace cookie

#endif
