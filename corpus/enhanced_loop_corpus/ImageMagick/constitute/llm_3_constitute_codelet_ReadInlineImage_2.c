#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using array indexing instead of pointer arithmetic
    size_t i = 0;
    for (; content[i] != ',' && content[i] != '\x00'; i++)
        ;
    p = content + i;
}
