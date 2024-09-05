#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

#include "token_da.h"

bool lex(const char* filepath, Token_da* tokens);

#endif  // !LEXER_H
