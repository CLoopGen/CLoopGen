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
    // Variant 1: Increased computational intensity with unrolled inner operations and extended trip count
    int local_bit_mask = bit_mask;
    int local_retval = retval;
    int local_shift2 = shift2 + (shift2 > 0 ? 1 : 0);  // Slight increase in trip count

    for (i = 0; i < local_shift2; i++) {
        guess = local_retval + local_bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + local_bit_mask + (local_bit_mask >> 1)) >> bits);  // Extra term for complexity
        if (x >= square) {
            local_retval += local_bit_mask;
        }
        // Additional arithmetic to increase computational load
        local_bit_mask = (local_bit_mask >> 1) | (local_bit_mask >> 3);
    }
    retval = local_retval;
    bit_mask = local_bit_mask;
}
