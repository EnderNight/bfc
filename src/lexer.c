#include "lexer.h"

#include <stdio.h>

#include "token.h"
#include "token_da.h"

bool lex(const char* filepath, Token_da* tokens) {
  FILE* program = fopen(filepath, "r");

  if (!program) {
    perror("lex");
    return false;
  }

  *tokens = Token_da_init();
  Token_da stack = Token_da_init();
  char c = fgetc(program);
  char tmp;
  size_t amount;
  Token token, tmp_token;

  while (c != EOF) {
    switch (c) {
      case '>':
      case '<':
      case '+':
      case '-':
      case '.':
      case ',':
        amount = 1;
        tmp = fgetc(program);
        while (tmp == c) {
          amount++;
          tmp = fgetc(program);
        }
        token = Token_init(c, amount, 0);
        Token_da_push(tokens, &token);

        ungetc(tmp, program);
        break;
      case '[':
        token = Token_init(LBRACK, 1, tokens->length);
        Token_da_push(tokens, &token);
        Token_da_push(&stack, &token);
        break;
      case ']':
        Token_da_pop(&stack, &token);
        tmp_token = Token_init(RBRACK, 1, token.index);
        tokens->array[token.index].index = tokens->length;
        Token_da_push(tokens, &tmp_token);
        break;

      default:
        break;
    }

    c = fgetc(program);
  }

  Token_da_free(&stack);

  return true;
}
