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
    // Variant 2: Consecutive memory layout access via struct to enforce sequential access pattern
    // Bundle loop-related variables into a struct to simulate consecutive memory layout access
    struct LoopState {
        int retval;
        int bit_mask;
        int guess;
        int square;
        int dummy_padding[4]; // Ensure spacing to simulate realistic layout
    } state;

    // Initialize struct from global values
    state.retval = retval;
    state.bit_mask = bit_mask;
    state.guess = guess;
    state.square = square;

    for (i = 0; i < shift2; i++) {
        // Sequential field access in struct simulates consecutive memory access
        state.guess = state.retval + state.bit_mask;
        accu = (int64_t)state.guess * state.guess;
        state.square = (int)((accu + state.bit_mask) >> bits);
        if (x >= state.square)
            state.retval += state.bit_mask;
        state.bit_mask >>= 1;
    }

    // Update globals from final struct state
    retval = state.retval;
    bit_mask = state.bit_mask;
    guess = state.guess;
    square = state.square;
}
