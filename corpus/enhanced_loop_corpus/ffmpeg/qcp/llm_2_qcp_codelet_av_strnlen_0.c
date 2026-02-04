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
    size_t stride = 2;
    i = 0;
    // First pass: strided access
    for (; i + stride <= len; i += stride) {
        if (!s[i]) {
            i = i - (stride - 1); // Adjust index to point to first zero in stride
            break;
        }
        if (!s[i + 1]) {
            i++;
            break;
        }
    }
    // Second pass: linear continuation from last checked position
    for (; i < len && s[i]; i++)
        ;
}
