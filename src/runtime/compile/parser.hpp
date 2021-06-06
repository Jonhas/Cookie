#ifndef PARSER_HPP
#define PARSER_HPP

#include "ast/ast_headers.hpp"
#include <vector>

namespace cookie {

template <typename T> class parser {
public:
  explicit parser(std::vector<cookie::token> &tok)
      : tokens(std::move(tok)), token_position(0) {}

  std::unique_ptr<cookie::node<cookie::token>> parse_program();

  [[nodiscard("Required for identifier parsing")]] std::unique_ptr<
      cookie::identifier_expression<cookie::token>>
  parse_identifier();

  [[nodiscard("Required for aug operator parsing")]] std::unique_ptr<
      cookie::aug_operator_expr<cookie::token>>
  parse_aug_operator();

  [[nodiscard("Required for int literal parsing")]] std::unique_ptr<
      cookie::int_expression<cookie::token>>
  parse_int_expression();

  [[nodiscard("Required for double literal parsing")]] std::unique_ptr<
      cookie::double_expression<cookie::token>>
  parse_double_expression();

  [[nodiscard("Required for string literal parsing")]] std::unique_ptr<
      cookie::node<cookie::token>>
  parse_string_literal();

  [[nodiscard("Required for char literal parsing")]] std::unique_ptr<
      cookie::node<cookie::token>>
  parse_char_literal();

  std::vector<cookie::token> tokens;
  size_t token_position;
};
} // namespace cookie

#endif
