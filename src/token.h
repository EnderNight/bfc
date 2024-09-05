#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

typedef enum {
  RIGHT = '>',
  LEFT = '<',
  PLUS = '+',
  MINUS = '-',
  DOT = '.',
  COMMA = ',',
  LBRACK = '[',
  RBRACK = ']',
} TokenType;

typedef struct {
  TokenType type;
  size_t amount;
  size_t index;
} Token;

Token Token_init(TokenType type, size_t amount, size_t index);
void Token_print(Token* token);

#endif  // !TOKEN_H
