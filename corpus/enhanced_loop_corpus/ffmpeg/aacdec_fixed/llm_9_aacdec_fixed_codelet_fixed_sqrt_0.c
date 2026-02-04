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
    // Variant 2: Reduced arithmetic density and halved trip count with simplified condition approximation
    for (i = 0; i < shift2 / 2; i++) {
        // Use approximate square via linear expansion: (a+b)^2 ≈ a^2 + 2ab (skip full multiply)
        int64_t base_accu = (int64_t)retval * retval;
        int64_t cross_term = 2LL * retval * bit_mask;
        accu = base_accu + cross_term + ((int64_t)bit_mask * bit_mask); // Still compute full but less frequently
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 2; // Shift by 2 to match halved loop count
    }
}
