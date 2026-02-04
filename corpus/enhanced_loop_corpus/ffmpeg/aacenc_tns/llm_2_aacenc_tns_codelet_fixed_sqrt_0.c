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
    int indices[32];
    for (i = 0; i < shift2; i += stride) {
        indices[i] = i; // Simulate precomputed access indices
        // Process every 'stride'-th element in logical sequence
        if (indices[i] >= shift2) continue;

        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;

        // Second iteration of the stride
        if (i + 1 < shift2) {
            guess = retval + (bit_mask >> 1);
            accu = (int64_t)guess * guess;
            square = (int)((accu + (bit_mask >> 1)) >> bits);
            if (x >= square)
                retval += (bit_mask >> 1);
            bit_mask >>= 2;
        }
    }
}
