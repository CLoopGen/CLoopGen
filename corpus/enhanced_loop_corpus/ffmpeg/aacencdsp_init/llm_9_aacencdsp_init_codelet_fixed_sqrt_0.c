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
    // Variant 2: Reduced computational intensity with higher trip count via splitting each original step into two phases
    // Each original iteration is split into two, doubling the trip count but simplifying operations per phase
    int j;
    int double_shift = shift2 * 2;
    for (j = 0; j < double_shift; j++) {
        if (j % 2 == 0) {
            // Phase 1: Compute guess and intermediate values
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
        } else {
            // Phase 2: Use computed values to update retval
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
