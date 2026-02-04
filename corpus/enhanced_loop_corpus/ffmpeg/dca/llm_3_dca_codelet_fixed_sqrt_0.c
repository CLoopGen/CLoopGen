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
    // Variant 2: Consecutive memory access pattern via simulated array traversal
    // Simulate consecutive accesses by grouping variables into a structure and iterating
    // through their addresses in order, mimicking sequential cache-friendly access.
    struct State {
        int retval;
        int bit_mask;
        int guess;
        int square;
    } state;

    // Initialize the struct with current global values
    state.retval = retval;
    state.bit_mask = bit_mask;
    state.guess = guess;
    state.square = square;

    int *seq_access[] = {&state.retval, &state.bit_mask, &state.guess, &state.square}; // Consecutive layout
    int n = sizeof(seq_access) / sizeof(seq_access[0]);

    for (i = 0; i < shift2; i++) {
        // Sequentially touch each variable in order (even if not all used)
        for (int j = 0; j < n; j++) {
            volatile int dummy = *seq_access[j]; // Enforce access
            (void)dummy;
        }

        // Main computation using structured copies
        state.guess = state.retval + state.bit_mask;
        accu = (int64_t)state.guess * state.guess;
        state.square = (int)((accu + state.bit_mask) >> bits);
        if (x >= state.square)
            state.retval += state.bit_mask;
        state.bit_mask >>= 1;
    }

    // Update globals from final state
    retval = state.retval;
    bit_mask = state.bit_mask;
    guess = state.guess;
    square = state.square;
}
