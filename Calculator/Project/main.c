#include <stdio.h>
#include "includes\String.h"

int main(void)
{
    String str = String_new(STRING_DEFAULT_CAPACITY);
    String_push(&str, 'a');
    String_push(&str, 'p');
    String_push(&str, 'p');
    String_push(&str, 'l');
    String_push(&str, 'e');
    String_push(&str, 's');
    String_push(&str, 'a');
    String_push(&str, 'u');
    String_push(&str, 'c');
    String_push(&str, 'e');
    String_push(&str, ' ');
    String_push(&str, 'i');
    String_push(&str, 's');
    String_push(&str, ' ');
    String_push(&str, 'y');
    String_push(&str, 'u');
    String_push(&str, 'm');
    String_push(&str, 'm');
    String_push(&str, 'y');
    String_push(&str, '!');

    puts(str);

    String_delete(&str);


    return 0;
}
