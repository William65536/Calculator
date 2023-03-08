#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>
#include <stdbool.h>

#define TOKEN_DEFAULT_CAPACITY 0

typedef enum {
    TOKEN_TYPE_NONE,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_LPAREN,
    TOKEN_TYPE_RPAREN
} TokenType;

typedef struct {
    TokenType type;
    union {
        double number;
        double (*operator)(double, double);
    };
    size_t col;
} Token;

typedef struct TokenList TokenList;

TokenList *TokenList_new(size_t initcap);

void TokenList_delete(TokenList **list);

bool TokenList_push(TokenList **list, Token token);

void TokenList_clear(TokenList *list);

#endif
