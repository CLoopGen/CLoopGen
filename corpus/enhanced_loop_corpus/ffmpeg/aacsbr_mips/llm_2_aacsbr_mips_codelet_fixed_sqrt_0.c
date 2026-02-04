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
    // Variant 1: Strided memory access pattern simulation via index scaling
    // Though no arrays are explicitly used, we simulate strided behavior by modifying how bit_mask is updated in strides
    int stride = 2;
    for (i = 0; i < shift2; i += stride) {
        // Unroll-like effect with stride: process two logical iterations per physical iteration
        // First sub-iteration
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;

        // Second sub-iteration (simulating strided progression)
        if (i + 1 < shift2) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
