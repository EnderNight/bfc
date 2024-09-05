#include "token.h"

#include <stdio.h>

Token Token_init(TokenType type, size_t amount, size_t index) {
  Token token = {
      .type = type,
      .amount = amount,
      .index = index,
  };

  return token;
}

void Token_print(Token* token) {
  if (!token) return;

  printf("Token (");

  switch (token->type) {
    case RIGHT:
      printf("RIGHT");
      break;
    case LEFT:
      printf("LEFT");
      break;
    case PLUS:
      printf("PLUS");
      break;
    case MINUS:
      printf("MINUS");
      break;
    case DOT:
      printf("DOT");
      break;
    case COMMA:
      printf("COMMA");
      break;
    case LBRACK:
      printf("LBRACK");
      break;
    case RBRACK:
      printf("RBRACK");
      break;
    default:
      printf("ERROR");
      break;
  }

  printf(", %lu, %lu)", token->amount, token->index);
}
