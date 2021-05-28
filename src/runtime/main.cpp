#include "compile/ast/identifier_expression.hpp"
#include "compile/compile.hpp"
#include <cstdio>
int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Cookie: Fatal Error, No Input file\n");
    return -1;
  }

  if (!argv[1]) {
    fprintf(stderr, "Cookie: Invalid Input File\n");
    return -1;
  }
  compile_file(argv[1]);
  cookie::identifier_expression<cookie::token> iden(
      cookie::token(cookie::token_type::token_identifier, "foo"));
  std::cout << iden.expressionNode() << '\n';
  return 0;
}
