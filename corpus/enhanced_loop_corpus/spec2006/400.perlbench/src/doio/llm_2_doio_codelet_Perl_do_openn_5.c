#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing instead of pointer arithmetic
    size_t i = 0;
    for (; (type[i] == ' ' || type[i] == '\t' || type[i] == '\n' || type[i] == '\r' || type[i] == '\f'); i++)
        ;
    type += i;
}
