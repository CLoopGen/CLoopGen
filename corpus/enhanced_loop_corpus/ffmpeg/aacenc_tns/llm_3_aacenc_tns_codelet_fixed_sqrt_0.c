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
    // Variant 2: Consecutive access pattern with unrolled structure to simulate linear traversal
    // Unroll the loop by a factor of 2 to create consecutive operations, mimicking optimized linear access
    int unroll_factor = 2;
    int remaining = shift2 % unroll_factor;
    
    // Full unrolled pairs
    for (i = 0; i < shift2 - remaining; i += unroll_factor) {
        // First operation in unrolled pair
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        int temp_bit_mask = bit_mask >> 1;

        // Second operation
        guess = retval + temp_bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + temp_bit_mask) >> bits);
        if (x >= square)
            retval += temp_bit_mask;
        bit_mask >>= 2;
    }

    // Handle remainder with standard step
    for (; i < shift2; i++) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
