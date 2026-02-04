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
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    int indices[256]; // Local index map, assuming reasonable bound on size
    for (int i = 0; i < (size < 256 ? size : 256); i++) {
        indices[i] = i; // Identity mapping for simplicity, could be randomized or reordered
    }
    dsize = 0;
    for (int i = 0; i < (size < 256 ? size : 256); i++) {
        *dst++ = src[indices[i]];
        dsize++;
        if (dsize >= size) break;
    }
}
