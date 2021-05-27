#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "statement.hpp"

namespace cookie {
/*
 *   Root node for every AST the parser produces
 */
template <typename T> class program : public cookie::Node<T> {
public:
  std::vector<std::unique_ptr<cookie::statement>> statements;
  inline std::string token_literal() {
    if (statements.size() > 0)
      return statements[0]->token_literal();
    else
      return "empty statements";
  }
};
} // namespace cookie

#endif