#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then adjust if needed)
    size_t step = 2;
    i = 0;
    for (; i < len && i + step/2 < len; i += step) {
        if (!s[i]) break;
        if (!s[i + 1]) {
            i++;
            break;
        }
    }
    // Handle remaining elements sequentially if loop ended early
    for (; i < len && s[i]; i++)
        ;
}
