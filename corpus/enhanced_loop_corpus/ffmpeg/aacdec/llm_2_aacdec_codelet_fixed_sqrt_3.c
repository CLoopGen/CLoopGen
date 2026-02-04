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
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride of 2
    // We simulate an array access pattern by treating 'bit_mask' as part of a logical array accessed with stride
    int stride = 2;
    int indices[32];
    for (i = 0; i < shift2; i += stride) {
        indices[i] = i; // Precompute strided indices (simulated pattern)
    }
    for (i = 0; i < shift2; i++) {
        int idx = indices[i]; // Logical index usage (simulating non-unit stride effect)
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
