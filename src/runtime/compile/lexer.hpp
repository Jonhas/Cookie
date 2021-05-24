#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <memory>

namespace cookie {
class lexer final {
public:
  lexer(std::string source, size_t position)
      : source(std::move(source)), position(position) {}

  std::unique_ptr<token> tokenize();

  std::unique_ptr<token> evaluate_keywords_or_identifiers();
  std::unique_ptr<token> evaluate_string_and_advance();
  std::unique_ptr<token> evaluate_char_and_advance();
  std::unique_ptr<token> evaluate_numbers_and_advance();
  std::unique_ptr<token> evaluate_comparison_and_advance();
  std::unique_ptr<token> evaluate_delimeters_and_advance();
  std::unique_ptr<token> evaluate_arithmetic_and_advance();

  void lexer_advance(size_t amount = 1);
  bool check_eof() const;
  char peek(size_t following = 0) const;

  std::string source{};
  size_t position{};
};
} // namespace cookie

#endif