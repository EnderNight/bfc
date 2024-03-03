#include "lexer/lexer.hh"

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include "lexer/token.hh"

namespace bfc::lexer
{

    size_t get_amount(const std::string& line, size_t& pos)
    {
        char c = line[pos];
        size_t amount = 0;

        while (pos < line.length() && line[pos] == c)
        {
            pos++;
            amount++;
        }

        return amount;
    }

    bool is_reserved(char c)
    {
        return c == '+' || c == '-' || c == '>' || c == '<' || c == '.'
            || c == ',' || c == '[' || c == ']';
    }

    std::vector<Token> lex(std::istream& is)
    {
        std::vector<Token> res;

        std::string line;

        while (std::getline(is, line))
        {
            size_t pos = 0;

            while (pos < line.length())
            {
                char c = line[pos];
                if (is_reserved(c))
                {
                    size_t amount = get_amount(line, pos);
                    TokenType type;

                    switch (c)
                    {
                    case '+':
                        type = TokenType::TOKEN_PLUS;
                        break;
                    case '-':
                        type = TokenType::TOKEN_MINUS;
                        break;
                    case '<':
                        type = TokenType::TOKEN_LEFT_ARROW;
                        break;
                    case '>':
                        type = TokenType::TOKEN_RIGHT_ARROW;
                        break;
                    case ']':
                        type = TokenType::TOKEN_RIGHT_BRACKET;
                        break;
                    case '[':
                        type = TokenType::TOKEN_LEFT_BRACKET;
                        break;
                    case '.':
                        type = TokenType::TOKEN_DOT;
                        break;
                    case ',':
                        type = TokenType::TOKEN_COMA;
                        break;
                    }

                    res.push_back(Token(type, amount));
                }
                else
                {
                    pos++;
                }
            }
        }

        return res;
    }

} // namespace bfc::lexer
