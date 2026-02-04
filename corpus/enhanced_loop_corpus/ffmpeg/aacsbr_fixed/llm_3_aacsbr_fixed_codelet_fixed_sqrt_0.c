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
    // Variant 2: Consecutive memory access pattern via linear traversal of a simulated state buffer
    // Pack relevant scalar variables into a contiguous integer array and update them consecutively
    // to promote cache locality and sequential memory behavior.
    int state[5]; // Simulated buffer: [retval, bit_mask, guess, square, temp placeholder]
    state[0] = retval;
    state[1] = bit_mask;
    for (i = 0; i < shift2; i++) {
        // Sequential access: update fields in order to promote spatial locality
        state[2] = state[0] + state[1];                    // guess
        accu = (int64_t)state[2] * state[2];
        state[3] = (int)((accu + state[1]) >> bits);       // square
        if (x >= state[3])
            state[0] += state[1];                          // update retval
        state[1] >>= 1;                                    // bit_mask >>= 1
    }
    // Update extern variables from final state
    retval = state[0];
    bit_mask = state[1];
}
