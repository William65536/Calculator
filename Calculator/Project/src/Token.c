#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "..\includes\Token.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define TOKEN_LIST_DEFAULT_INIT_CAP 10
#define TOKEN_LIST_RESIZE_MULTIPLIER 2

struct TokenList {
    size_t size, cap;
    Token tokens[];
};

TokenList *TokenList_new(size_t initcap)
{
    TokenList *ret = malloc(sizeof *ret + max(initcap, TOKEN_LIST_DEFAULT_INIT_CAP) * sizeof *ret->tokens);

    if (ret == NULL)
        return NULL;

    ret->cap = max(initcap, TOKEN_LIST_DEFAULT_INIT_CAP);
    ret->size = 0;

    return ret;
}

void TokenList_delete(TokenList **list)
{
    assert(list != NULL && *list != NULL);

    free(*list);
    *list = NULL;
}

static bool TokenList_resize(TokenList **list)
{
    assert(list != NULL && *list != NULL);

    TokenList *temp = realloc(*list, sizeof **list + (*list)->cap * TOKEN_LIST_RESIZE_MULTIPLIER * sizeof *(*list)->tokens);

    if (temp == NULL)
        return false;

    *list = temp;
    (*list)->cap *= TOKEN_LIST_RESIZE_MULTIPLIER;

    return true;
}

bool TokenList_push(TokenList **list, Token token)
{
    assert(list != NULL && *list != NULL);

    if ((*list)->size + 1 > (*list)->cap)
        if (!TokenList_resize(list))
            return false;

    (*list)->tokens[(*list)->size] = token;
    (*list)->size++;

    return true;
}

void TokenList_clear(TokenList *list)
{
    assert(list != NULL);

    list->size = 0;
}
