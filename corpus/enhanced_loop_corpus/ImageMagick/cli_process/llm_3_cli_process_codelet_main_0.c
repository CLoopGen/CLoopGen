#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int arg_count;
extern char *args[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer array traversal using a pointer to pointer
    char **ptr = args;
    for (arg_count = 0; *ptr != (char *)((void *)0); arg_count++, ptr++)
        ;
}
