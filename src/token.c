#include "token.h"

#include <stdio.h>
#include <stdlib.h>

Token token_init(TokenType type, size_t amount, size_t index) {
  Token res = {
      .type = type,
      .amount = amount,
      .index = index,
  };

  return res;
}

void token_print(Token* token) {
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
  }

  printf(", %lu, %lu)", token->amount, token->index);
}

TokenList* token_list_init(void) {
  TokenList* res = calloc(1, sizeof(TokenList));

  if (!res) {
    perror("token_list_init");
    return NULL;
  }

  return res;
}

bool token_list_add(TokenList* tokens, Token* token) {
  if (!tokens || !token) return false;

  if (tokens->length >= tokens->capacity) {
    tokens->capacity = tokens->capacity ? tokens->capacity * 2 : 1;
    tokens->list = realloc(tokens->list, sizeof(Token) * tokens->capacity);

    if (!tokens->list) {
      perror("tokens_add");
      return false;
    }
  }

  tokens->list[tokens->length++] = *token;

  return true;
}

void token_list_free(TokenList** tokens) {
  if (!tokens || !*tokens) return;

  free((*tokens)->list);
  free(*tokens);

  *tokens = NULL;
}

void token_list_print(TokenList* tokens) {
  if (!tokens) return;

  for (size_t i = 0; i < tokens->length; i++) {
    token_print(&tokens->list[i]);
    putchar('\n');
  }
}

TokenStack* token_stack_init(void) {
  TokenStack* res = malloc(sizeof(TokenStack));

  if (!res) {
    perror("token_stack_init");
    return NULL;
  }

  res->top = 0;
  res->stack = token_list_init();

  if (!res->stack) {
    free(res);
    return NULL;
  }

  return res;
}

bool token_stack_empty(TokenStack* stack) {
  if (!stack) return false;

  return stack->top == -1;
}

bool token_stack_push(TokenStack* stack, Token* token) {
  if (!stack || !token) return false;

  if (token_list_add(stack->stack, token)) {
    stack->top++;
    return true;
  }

  return false;
}

Token token_stack_pop(TokenStack* stack) {
  if (!stack || stack->top == -1) return token_init(0, 0, 0);

  Token res = stack->stack->list[stack->top--];
  stack->stack->length--;

  return res;
}

void token_stack_free(TokenStack** stack) {
  if (!stack || !*stack) return;

  token_list_free(&(*stack)->stack);
  free(*stack);
  *stack = NULL;
}

void token_stack_print(TokenStack* stack) {
  if (!stack) return;

  for (ssize_t i = stack->top; i > -1; i--) {
    token_print(&stack->stack->list[i]);
    putchar('\n');
  }
}
