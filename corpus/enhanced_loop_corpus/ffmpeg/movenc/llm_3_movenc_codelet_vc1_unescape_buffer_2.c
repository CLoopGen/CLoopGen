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
    int indices[256]; // Assume size <= 256 for simplicity and stack allocation
    if (size > 256) return; // Prevent buffer overflow

    for (int i = 0; i < size; i++) {
        indices[i] = i; // Identity mapping, could be randomized or reordered in practice
    }

    for (dsize = 0; dsize < size; dsize++) {
        *dst++ = src[indices[dsize]];
    }
}
