#include "compile.hpp"
#include <vector>

void compile(const std::string filename) {
  size_t position = 0;
  auto lexer = std::make_unique<cookie::lexer>(filename, position);
  std::vector<std::unique_ptr<cookie::token>> tokens;
  while (true) {
    auto token = lexer->tokenize();
    if (!token) {
      perror("Invalid token initialization\n");
      break;
    }
    std::cout << "Token (" << token->value << '\n';
    if (token->type == cookie::token_type::token_error ||
        token->type == cookie::token_type::token_eof)
      break;
  }
}

void compile_file(const char *filename) {
  const std::string source = read_file(filename);
  compile(source);
}