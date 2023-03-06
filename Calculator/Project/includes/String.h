#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdbool.h>

#define STRING_DEFAULT_CAPACITY 0

typedef char *String;

String String_new(size_t initcap);

void String_delete(String *str);

bool String_push(String *str, char c);

typedef struct {
    size_t size;
    const char *str_ptr;
} StringView;

#endif
