#pragma once

#include <vector>

#include "lexer/token.hh"

namespace bfc::lexer
{

    std::vector<Token> lex(std::istream& is);

} // namespace bfc::lexer
