#include <stdio.h>

#include "executor.h"
#include "lexer.h"
#include "token_da.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of arguments\n");
    fprintf(stderr, "Usage: bfc <FILE>\n");
    return 1;
  }

  Token_da tokens = Token_da_init();

  lex(argv[1], &tokens);

  // for (size_t i = 0; i < tokens.length; i++) {
  //   Token_print(&tokens.array[i]);
  //   putchar('\n');
  // }

  execute(&tokens);

  Token_da_free(&tokens);

  return 0;
}
