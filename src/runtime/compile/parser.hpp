#ifndef PARSER_HPP
#define PARSER_HPP

#include "ast/ast_headers.hpp"
#include <vector>

namespace cookie {

template <typename T> class parser {
public:
  explicit parser(std::vector<cookie::token> &tokens)
      : tokens(std::move(tokens)), token_position(0) {}

  [[nodiscard("Required for identifier parsing")]] 
  std::unique_ptr<cookie::identifier<cookie::token>> parse_identifier();

  [[nodiscard("Required for aug operator parsing")]]
  std::unique_ptr<cookie::aug_operator<cookie::token>> parse_aug_operator(); 
  
   
  std::vector<cookie::token> tokens{};
  size_t token_position{};
};
} // namespace cookie

#endif