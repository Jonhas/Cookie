#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <memory>

namespace cookie {
class lexer final {
public:
  explicit lexer(std::string source) : source(std::move(source)) {}

  std::unique_ptr<token> tokenize();

  std::unique_ptr<token> evaluate_keywords_or_identifiers();
  std::unique_ptr<token> evaluate_string_and_advance();
  std::unique_ptr<token> evaluate_char_and_advance();
  std::unique_ptr<token> evaluate_numbers_and_advance();
  std::unique_ptr<token> evaluate_comparison_and_advance();
  std::unique_ptr<token> evaluate_delimeters_and_advance();
  std::unique_ptr<token> evaluate_arithmetic_and_advance();

  void lexer_advance(size_t amount);
  bool check_eof() const;
  char peek(size_t following = 0);

  std::string source{};
};
} // namespace cookie

#endif