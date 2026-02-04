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
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    int indices[2] = {0, 1}; // Simulated small lookup pattern to mimic indirect access
    int idx = 0;
    for (dsize = 0; dsize < size; dsize++) {
        int effective_idx = (dsize % 2 == 0) ? dsize + indices[0] : dsize - indices[1];
        effective_idx = effective_idx % size;
        if (effective_idx >= 0 && effective_idx < size) {
            *dst++ = src[effective_idx];
        }
    }
}
