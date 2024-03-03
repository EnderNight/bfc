#include "lexer/token.hh"

#include <ostream>
#include <string>

namespace bfc::lexer
{
    Token::Token(TokenType type, size_t amount)
        : type_(type)
        , amount_(amount)
    {}

    TokenType Token::get_type() const
    {
        return type_;
    }

    size_t Token::get_amount() const
    {
        return amount_;
    }

    std::ostream& operator<<(std::ostream& os, const Token& token)
    {
        os << "type: " << token.type_ << ", amount: " << token.amount_;

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const TokenType type)
    {
        switch (type)
        {
        case TokenType::TOKEN_LEFT_ARROW:
            os << "TOKEN_LEFT_ARROW";
            break;
        case TokenType::TOKEN_RIGHT_ARROW:
            os << "TOKEN_RIGHT_ARROW";
            break;
        case TokenType::TOKEN_PLUS:
            os << "TOKEN_PLUS";
            break;
        case TokenType::TOKEN_MINUS:
            os << "TOKEN_MINUS";
            break;
        case TokenType::TOKEN_DOT:
            os << "TOKEN_DOT";
            break;
        case TokenType::TOKEN_COMA:
            os << "TOKEN_COMA";
            break;
        case TokenType::TOKEN_LEFT_BRACKET:
            os << "TOKEN_LEFT_BRACKET";
            break;
        case TokenType::TOKEN_RIGHT_BRACKET:
            os << "TOKEN_RIGHT_BRACKET";
            break;
        }

        return os;
    }

} // namespace bfs::lexer
