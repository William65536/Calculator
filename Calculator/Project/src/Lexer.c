#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "..\includes\String.h"
#include "..\includes\Token.h"
#include "..\includes\Lexer.h"

struct Lexer {
    String input;
    const char *rest;
    TokenList *tokens;
    TokenType prevtype;
};

Lexer *Lexer_new(void)
{
    Lexer *ret = malloc(sizeof *ret);

    if (ret == NULL)
        return NULL;

    ret->input = String_new(STRING_DEFAULT_CAPACITY);

    if (ret->input == NULL) {
        free(ret);
        return NULL;
    }

    ret->tokens = TokenList_new(TOKEN_DEFAULT_CAPACITY);

    if (ret->tokens == NULL) {
        String_delete(&ret->input);
        free(ret);
        return NULL;
    }

    ret->prevtype = TOKEN_TYPE_NONE;
    ret->rest = ret->input;

    return ret;
}

void Lexer_delete(Lexer **lexer)
{
    assert(lexer != NULL && *lexer != NULL);

    String_delete(&(*lexer)->input);

    TokenList_delete(&(*lexer)->tokens);

    free(*lexer);
    *lexer = NULL;
}

bool Lexer_from_FILE(Lexer *lexer, FILE *file)
{
    assert(lexer != NULL);
    assert(file != NULL);

    assert(lexer->tokens != NULL);
    TokenList_clear(lexer->tokens);

    assert(lexer->input != NULL);
    String_clear(lexer->input);

    int c;

    while ((c = getc(file)) != EOF && c != '\0' && c != '\n' && c != '\r')
        if (!String_push(&lexer->input, c))
            return false;

    lexer->prevtype = TOKEN_TYPE_NONE;
    lexer->rest = lexer->input;

    return true;
}
