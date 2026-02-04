#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int indices[256]; // Local index map, assuming reasonable bound
    int limit = size < 256 ? size : 256;
    for (int i = 0; i < limit; i++) {
        indices[i] = i; // Identity mapping for indirect access
    }
    for (dsize = 0; dsize < limit; dsize++) {
        *dst++ = src[indices[dsize]];
    }
}
