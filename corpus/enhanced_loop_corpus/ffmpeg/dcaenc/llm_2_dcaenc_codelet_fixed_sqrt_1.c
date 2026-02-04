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
    // Variant 1: Strided memory access pattern simulation using an array-like indexing with stride of 2
    // We simulate an array access pattern by unrolling the effect across iterations with a virtual stride.
    int stride = 2;
    int max_iter = (shift2 + stride - 1) / stride; // Adjust iteration count for strided access

    for (i = 0; i < max_iter; i++) {
        int eff_i = i * stride; // Effective index with stride
        if (eff_i >= shift2) break;

        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;

        // Second access in stride, if within bounds
        eff_i++;
        if (eff_i >= shift2) continue;

        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
