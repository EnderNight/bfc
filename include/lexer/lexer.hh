#pragma once

#include <vector>

#include "lexer/token.hh"

namespace bfc::lexer
{
    class Lexer
    {
    public:
        Lexer();

        Token peek();
        Token next();

    private:
        Token cur_tok_;
    };

    std::vector<Token> lex(std::istream& is);

} // namespace bfc::lexer
