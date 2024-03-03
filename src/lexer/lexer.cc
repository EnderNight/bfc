#include "lexer/lexer.hh"

#include <vector>

#include "lexer/token.hh"

namespace bfc::lexer
{
    Lexer::Lexer()
        : cur_tok_(Token(TokenType::TOKEN_START, 0))
    {}

    Token Lexer::peek()
    {
        return cur_tok_;
    }

    Token Lexer::next()
    {
        return cur_tok_;
    }

    std::vector<Token> lex(std::istream& is)
    {
        (void)is;
        std::vector<Token> res;

        return res;
    }

} // namespace bfc::lexer
