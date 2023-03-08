#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdbool.h>

typedef struct Lexer Lexer;

Lexer *Lexer_new(void);

void Lexer_delete(Lexer **lexer);

bool Lexer_from_FILE(Lexer *lexer, FILE *file);

#endif
