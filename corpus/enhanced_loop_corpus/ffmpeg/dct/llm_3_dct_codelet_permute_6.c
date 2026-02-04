#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    int16_t indices[64];
    for (int j = 0; j < 64; j++) {
        indices[j] = j; // Identity mapping for correctness, but allows for arbitrary reordering
    }
    for (i = 0; i < 64; i++) {
        int idx = indices[i]; // Simulate indirect access
        dst[idx] = src[idx];
    }
}
