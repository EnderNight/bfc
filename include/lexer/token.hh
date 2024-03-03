#pragma once

#include <cstddef>
#include <ostream>

namespace bfc::lexer
{
    enum class TokenType
    {
        TOKEN_EOF,
        TOKEN_START,
        TOKEN_LEFT_ARROW,
        TOKEN_RIGHT_ARROW,
        TOKEN_PLUS,
        TOKEN_MINUS,
        TOKEN_DOT,
        TOKEN_COMA,
        TOKEN_LEFT_BRACKET,
        TOKEN_RIGHT_BRACKET,
    };

    class Token
    {
    public:
        Token(TokenType type, size_t amount);

        TokenType get_type() const;
        size_t get_amount() const;

        friend std::ostream& operator<<(std::ostream& os, const Token& token);

    private:
        TokenType type_;
        size_t amount_; // TODO
    };

    std::ostream& operator<<(std::ostream& os, const Token& token);

    std::ostream& operator<<(std::ostream& os, const TokenType type);
} // namespace bfc::lexer
