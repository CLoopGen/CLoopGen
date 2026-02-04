#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    size_t step = 2;
    i = 0;
    // First pass: strided access
    for (; i + step <= len; i += step) {
        if (!s[i]) {
            i -= step - 1; // Adjust so that exit condition works correctly
            break;
        }
        if (!s[i + 1]) {
            i++;
            break;
        }
    }
    // Second pass: handle remaining elements sequentially
    for (; i < len && s[i]; i++)
        ;
}
