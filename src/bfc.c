#include <stdio.h>

#include "lexer.h"
#include "token.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments\n");
    puts("Usage: bfc <FILE>");
    return 1;
  }

  TokenList* tokens = lex(argv[1]);

  if (!tokens) return 1;

  token_list_print(tokens);

  token_list_free(&tokens);

  return 0;
}
