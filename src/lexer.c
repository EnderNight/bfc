#include "lexer.h"

#include <stdio.h>

#include "token.h"

TokenList* lex(const char* filepath) {
  TokenList* tokens = token_list_init();
  FILE* program = fopen(filepath, "r");

  if (!program || !tokens) {
    perror("lex");
    token_list_free(&tokens);
    return NULL;
  }

  char c = fgetc(program);
  char tmp = '\0';
  Token tok;
  size_t amount;

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
        ungetc(tmp, program);
        tok = token_init(c, amount, 0);
        token_list_add(tokens, &tok);
        break;
      case '[':
        tok = token_init(LBRACK, 1, 0);
        token_list_add(tokens, &tok);
        break;
      case ']':
        tok = token_init(RBRACK, 1, 0);
        token_list_add(tokens, &tok);
        break;
      default:
        break;
    }

    c = fgetc(program);
  }

  return tokens;
}
