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
    // We simulate an array access pattern by treating 'bit_mask' as part of an implicit sequence accessed with stride.
    int stride = 2;
    int temp_retval[64];  // Simulated storage to allow strided writes
    int temp_square[64];
    int temp_guess[64];

    for (i = 0; i < shift2; i += stride) {
        // Strided access: only every 'stride'-th element is updated, others skipped
        if (i + 0 < shift2) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
            temp_guess[i] = guess;
            temp_square[i] = square;
            temp_retval[i] = retval;
        }
        if (i + 1 < shift2) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
            temp_guess[i+1] = guess;
            temp_square[i+1] = square;
            temp_retval[i+1] = retval;
        }
    }
}
