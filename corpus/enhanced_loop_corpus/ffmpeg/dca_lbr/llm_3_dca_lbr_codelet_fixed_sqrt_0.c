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



void loop(){
    // Variant 2: Consecutive memory layout and access via a structure to enforce sequential memory access
    // Pack loop state into a struct to promote spatial locality and consecutive access
    struct LoopState {
        int retval;
        int bit_mask;
        int guess;
        int square;
        int x_copy; // local copy of x
        int shift2_copy; // local copy of shift2
    } state;

    // Initialize struct with external values (simulate consecutive loading)
    state.retval = retval;
    state.bit_mask = bit_mask;
    state.x_copy = x;
    state.shift2_copy = shift2;

    for (i = 0; i < state.shift2_copy; i++) {
        // Sequential field access in struct simulates consecutive memory access pattern
        state.guess = state.retval + state.bit_mask;
        accu = (int64_t)state.guess * state.guess;
        state.square = (int)((accu + state.bit_mask) >> bits);
        if (state.x_copy >= state.square)
            state.retval += state.bit_mask;
        state.bit_mask >>= 1;
    }

    // Write back final value to maintain semantics
    retval = state.retval;
}
