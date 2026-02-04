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
    // Variant 1: Increased computational intensity with unrolled operations and doubled effective trip count via smaller step
    bit_mask >>= 1; // Pre-adjust to maintain logic consistency
    for (i = 0; i < shift2; i += 2) {
        // Unroll two iterations into one, increasing arithmetic density
        int guess1 = retval + bit_mask;
        int64_t accu1 = (int64_t)guess1 * guess1;
        int square1 = (int)((accu1 + bit_mask) >> bits);
        if (x >= square1)
            retval += bit_mask;
        bit_mask >>= 1;

        int guess2 = retval + bit_mask;
        int64_t accu2 = (int64_t)guess2 * guess2;
        int square2 = (int)((accu2 + bit_mask) >> bits);
        if (x >= square2)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
