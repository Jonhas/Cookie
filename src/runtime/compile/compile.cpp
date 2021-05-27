#include "compile.hpp"

void compile(const std::string filename) {
  size_t position = 0;
  auto lexer = std::make_unique<cookie::lexer>(filename, position);
  std::vector<cookie::token> tokens;
  tokens = std::move(lexer->tokenize());
  for (const auto &t : tokens) {
    std::cout << "Token (" << t.type << ", " << t.value << ")" << '\n';
  }
  std::cout << "\n";
}

void compile_file(const char *filename) {
  const std::string source = read_file(filename);
  compile(source);
}