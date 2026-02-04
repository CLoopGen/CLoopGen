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
    int prev_retval = retval;
    for (i = 0; i < shift2; i++) {
        // Introduce artificial loop-carried dependency with extended use of accu from previous iteration
        int64_t delayed_accu = (i == 0) ? accu : (int64_t)(prev_retval + bit_mask) * (prev_retval + bit_mask);
        guess = prev_retval + bit_mask;
        accu = (int64_t)guess * guess;
        // Create RAW dependency: square depends on updated accu and bits
        square = (int)((delayed_accu + bit_mask) >> bits);
        if (x >= square)
            prev_retval += bit_mask;
        // Maintain WAW dependency on bit_mask with explicit ordering
        int next_bit_mask = bit_mask >> 1;
        bit_mask = next_bit_mask;
    }
    // Update shared state only once at end to reduce loop-carried WAW
    retval = prev_retval;
}
