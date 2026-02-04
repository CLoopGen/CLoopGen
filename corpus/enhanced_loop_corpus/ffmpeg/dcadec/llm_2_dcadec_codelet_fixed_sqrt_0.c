#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;
extern int shift2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using an array-like indexing with stride of 2
    // We simulate a strided access by treating scalar variables as elements of an array with fixed offsets.
    // This mimics accessing struct-of-arrays or padded data layouts.

    int state[8]; // Simulated packed state: [retval, bit_mask, guess, square, x, bits, shift2, dummy]
    state[0] = retval;
    state[1] = bit_mask;
    state[4] = x;
    state[5] = bits;
    state[6] = shift2;

    for (i = 0; i < state[6]; i++) {
        int idx_guess = (i * 2) % 8;          // Stride of 2, wrap-around indexing
        int idx_square = (idx_guess + 3) % 8;
        int idx_bitmask = (idx_guess + 1) % 8;

        state[idx_guess] = state[0] + state[1];
        accu = (int64_t)state[idx_guess] * state[idx_guess];
        state[idx_square] = (int)((accu + state[1]) >> state[5]);
        
        if (state[4] >= state[idx_square])
            state[0] += state[1];
        
        state[idx_bitmask] >>= 1;
    }

    // Update globals from final state
    retval = state[0];
    bit_mask = state[1];
}
