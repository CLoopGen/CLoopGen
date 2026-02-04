#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern uint8_t *iv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reordered access: even indices first, then odd
    for (i = 0; i < 8; i++) {
        int idx = indices[i];
        dst[idx] = src[idx] ^ iv[idx];
    }
}
