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
    // Variant 2: Reduced computational intensity with expanded trip count and simplified condition logic
    // Trip count is effectively doubled, but each iteration performs minimal work
    // Original body split into two phases via control logic, increasing loop iterations but lowering ops per iteration

    int phase = 0;
    for (i = 0; i < shift2 * 2; i++) {
        if (phase == 0) {
            // Phase 0: Compute guess and square
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
        } else {
            // Phase 1: Update retval and shift bit_mask
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
        // Toggle phase between 0 and 1
        phase = 1 - phase;
    }
}
