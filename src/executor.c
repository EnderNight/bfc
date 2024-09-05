#include "executor.h"

#include <stdio.h>

#include "token.h"

char MEMORY[MEMORY_SIZE] = {0};
size_t pos = 0;

bool execute(Token_da* tokens) {
  if (!tokens) return false;

  for (size_t ip = 0; ip < tokens->length; ip++) {
    Token token = tokens->array[ip];
    switch (token.type) {
      case RIGHT:
        pos += token.amount;
        break;
      case LEFT:
        pos -= token.amount;
        break;
      case PLUS:
        MEMORY[pos] += token.amount;
        break;
      case MINUS:
        MEMORY[pos] -= token.amount;
        break;
      case DOT:
        for (size_t j = 0; j < token.amount; j++) {
          putchar(MEMORY[pos]);
        }
        break;
      case COMMA:
        for (size_t j = 0; j < token.amount; j++) {
          MEMORY[pos] = getchar();
        }
        break;
      case LBRACK:
        if (!MEMORY[pos]) {
          ip = token.index;
          break;
        }
        break;
      case RBRACK:
        if (MEMORY[pos]) {
          ip = token.index;
          break;
        }
        break;
    }
  }

  return true;
}
