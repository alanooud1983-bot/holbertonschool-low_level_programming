/* 0-main.c */
#include <stdio.h>
#include "function_pointers.h"

void print_name_as_is(char *name)
{
    printf("%s\n", name);
}

int main(void)
{
    print_name("Bob", print_name_as_is);
    return (0);
}
