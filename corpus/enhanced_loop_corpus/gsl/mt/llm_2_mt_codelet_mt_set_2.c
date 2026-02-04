#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned long mt[624];
    int mti;
} mt_state_t;

extern mt_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd element in forward and backward pass)
    // First handle even indices, then odd indices to create a strided access pattern
    for (int j = 0; j < 2; j++) {
        for (i = 1 + j; i < 624; i += 2) {
            state->mt[i] = (1812433253UL * (state->mt[i - 1] ^ (state->mt[i - 1] >> 30)) + i);
            state->mt[i] &= 4294967295UL;
        }
    }
}
