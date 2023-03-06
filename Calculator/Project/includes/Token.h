#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_TYPE_NONE,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_LPAREN,
    TOKEN_TYPE_RPAREN
} TokenType;

typedef struct TokenList TokenList;

#endif
