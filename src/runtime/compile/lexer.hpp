#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <memory>
#include <vector>
namespace cookie {
class lexer final {
public:
  lexer(std::string source, size_t position)
      : source(std::move(source)), position(position) {}

  std::vector<token> tokenize();

  token evaluate_keywords_or_identifiers();
  token evaluate_string_and_advance();
  token evaluate_char_and_advance();
  token evaluate_numbers_and_advance();
  token evaluate_comparison_and_advance();
  token evaluate_delimeters_and_advance();
  token evaluate_arithmetic_and_advance();

  void lexer_advance(size_t amount = 1);
  bool check_eof() const;
  char peek(size_t following = 0) const;

  std::string source{};
  size_t position{};
};
} // namespace cookie

#endif