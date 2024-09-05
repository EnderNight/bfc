#ifndef TOKEN_H
#define TOKEN_H

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

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

typedef struct {
  Token* list;
  size_t length;
  size_t capacity;
} TokenList;

typedef struct {
  TokenList* stack;
  ssize_t top;
} TokenStack;

Token token_init(TokenType type, size_t amount, size_t index);
void token_print(Token* token);

TokenList* token_list_init(void);
bool token_list_add(TokenList* tokens, Token* token);
void token_list_free(TokenList** tokens);
void token_list_print(TokenList* tokens);

TokenStack* token_stack_init(void);
bool token_stack_empty(TokenStack* stack);
bool token_stack_push(TokenStack* stack, Token* token);
Token token_stack_pop(TokenStack* stack);
void token_stack_free(TokenStack** stack);
void token_stack_print(TokenStack* stack);

#endif  // !TOKEN_H
