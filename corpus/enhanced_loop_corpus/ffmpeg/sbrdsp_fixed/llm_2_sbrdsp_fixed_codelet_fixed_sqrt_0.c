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
    // We simulate an array access pattern by treating 'bit_mask' as part of an implicit data sequence accessed with a fixed stride.
    int stride = 2;
    int indices[32];
    for (i = 0; i < shift2; i += stride) {
        indices[i] = i; // Precompute access indices to simulate non-consecutive access
    }
    for (i = 0; i < shift2; i++) {
        int idx = indices[i]; // Use precomputed index (simulates structured strided access)
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        // Simulate strided update: only update every 2nd iteration effect (conceptual)
        if ((i % 2) == 0) {
            bit_mask >>= 1;
        }
    }
}
