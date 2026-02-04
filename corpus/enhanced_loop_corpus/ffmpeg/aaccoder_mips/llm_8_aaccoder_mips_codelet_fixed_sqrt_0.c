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
    // Variant 1: Increased computational intensity with unrolled operations and doubled effective trip count via smaller steps
    int local_bit_mask = bit_mask;
    int local_retval = retval;
    int local_shift2 = shift2;

    for (i = 0; i < local_shift2; i += 2) {
        // First iteration step
        int guess1 = local_retval + local_bit_mask;
        int64_t accu1 = (int64_t)guess1 * guess1;
        int square1 = (int)((accu1 + local_bit_mask) >> bits);
        if (x >= square1)
            local_retval += local_bit_mask;
        local_bit_mask >>= 1;

        // Second iteration step, if within bounds
        if (i + 1 < local_shift2) {
            int guess2 = local_retval + local_bit_mask;
            int64_t accu2 = (int64_t)guess2 * guess2;
            int square2 = (int)((accu2 + local_bit_mask) >> bits);
            if (x >= square2)
                local_retval += local_bit_mask;
            local_bit_mask >>= 1;
        }
    }
    retval = local_retval;
    bit_mask = local_bit_mask;
}
