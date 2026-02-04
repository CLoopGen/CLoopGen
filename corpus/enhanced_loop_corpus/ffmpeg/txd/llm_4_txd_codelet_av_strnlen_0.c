#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (forward by 2, then linear cleanup)
    size_t stride = 2;
    for (i = 0; i + stride < len && s[i]; i += stride) {
        // Skip every other element in access pattern
    }
    // Resume sequential access from current i
    for (; i < len && s[i]; i++)
        ;
}
