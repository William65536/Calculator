#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "..\includes\String.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define STRING_DEFAULT_INIT_CAP 10
#define STRING_RESIZE_MULTIPLIER 2
#define String_to_InternalString(str) (InternalString *) (str - sizeof (InternalString))

typedef struct {
    size_t size, cap;
    char buf[];
} InternalString;

String String_new(size_t initcap)
{
    InternalString *ret = malloc(sizeof *ret + (max(initcap, STRING_DEFAULT_INIT_CAP) + 1) * sizeof *ret->buf);

    if (ret == NULL)
        return NULL;

    ret->cap = max(initcap, STRING_DEFAULT_INIT_CAP);
    ret->size = 0;
    ret->buf[0] = '\0';

    return ret->buf;
}

void String_delete(String *str)
{
    assert(str != NULL && *str != NULL);

    InternalString *internal_str = String_to_InternalString(*str);
    assert(internal_str != NULL);

    free(internal_str);
    *str = NULL;
}

static bool String_resize(String *str)
{
    assert(str != NULL && *str != NULL);

    InternalString *internal_str = String_to_InternalString(*str);
    assert(internal_str != NULL);

    InternalString *temp = realloc(internal_str, sizeof *internal_str + (internal_str->cap * STRING_RESIZE_MULTIPLIER + 1) * sizeof *internal_str->buf);

    if (temp == NULL)
        return false;

    temp->cap *= STRING_RESIZE_MULTIPLIER;

    *str = temp->buf;

    return true;
}

bool String_push(String *str, char c)
{
    assert(str != NULL && *str != NULL);
    assert(c != '\0');

    InternalString *internal_str = String_to_InternalString(*str);
    assert(internal_str != NULL);

    if (internal_str->size + 1 > internal_str->cap)
        if (!String_resize(str))
            return false;

    internal_str = String_to_InternalString(*str);
    internal_str->buf[internal_str->size] = c;
    internal_str->buf[internal_str->size + 1] = '\0';
    internal_str->size++;

    return true;
}

void String_clear(String str)
{
    assert(str != NULL);

    InternalString *internal_str = String_to_InternalString(str);
    assert(internal_str != NULL);

    internal_str->size = 0;

    str[0] = '\0';
}
