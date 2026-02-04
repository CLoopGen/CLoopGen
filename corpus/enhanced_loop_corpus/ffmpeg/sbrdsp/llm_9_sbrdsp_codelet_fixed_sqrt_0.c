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
    // Variant 2: Reduced computational intensity with increased trip count via splitting each original step
    // Each original operation is broken into two steps, doubling the iterations but simplifying per-step work
    int stage;
    int doubled_shift2 = shift2 * 2;
    for (i = 0; i < doubled_shift2; i++) {
        stage = i % 2;
        if (stage == 0) {
            // First stage: compute guess and square
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
        } else {
            // Second stage: compare and update
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
