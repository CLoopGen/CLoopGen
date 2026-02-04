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
    // Though no actual array is used, we simulate strided behavior in computation by processing "virtual" even indices only
    int stride = 2;
    for (i = 0; i < shift2; i += stride) {
        // Perform two operations per iteration to simulate strided access effect
        for (int s = 0; s < stride && i + s < shift2; s++) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
