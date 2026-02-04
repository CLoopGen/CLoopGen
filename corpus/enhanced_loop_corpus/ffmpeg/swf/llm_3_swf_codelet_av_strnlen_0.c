#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive double-step access using temporary pointer arithmetic
    char *p = s;
    for (i = 0; i + 1 < len && p[i] && p[i + 1]; i += 2)
        ;
}
