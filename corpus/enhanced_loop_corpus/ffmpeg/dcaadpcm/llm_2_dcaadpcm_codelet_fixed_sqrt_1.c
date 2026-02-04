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
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride of 2
    // We simulate an array access pattern by treating 'bit_mask' as part of a virtual array accessed with stride
    int stride = 2;
    int max_iter = shift2 / stride;

    for (i = 0; i < max_iter; i++) {
        int effective_i = i * stride;
        guess = retval + (bit_mask >> effective_i);
        accu = (int64_t)guess * guess;
        square = (int)((accu + (bit_mask >> effective_i)) >> bits);
        if (x >= square)
            retval += (bit_mask >> effective_i);
    }

    // Handle remaining iterations if shift2 is not divisible by stride
    for (i = max_iter * stride; i < shift2; i++) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
