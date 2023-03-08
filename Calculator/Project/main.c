#include <stdio.h>
#include "includes\String.h"

int main(void)
{
    String str = String_new(STRING_DEFAULT_CAPACITY);

    for (size_t i = 0; i < 10000; i++)
        String_push(&str, 'a');

    puts(str);

    String_delete(&str);


    return 0;
}
