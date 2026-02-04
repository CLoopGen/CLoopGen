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
    // Variant 2: Reduced arithmetic density and modified trip count with conditional skip
    int local_x = x;
    int local_bits = bits;
    int local_shift2 = shift2 / 2;  // Halved trip count to reduce computation

    for (i = 0; i < local_shift2; i++) {
        // Skip every other bit_mask update to reduce operations
        if (i % 2 == 0) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> local_bits);
            if (local_x >= square)
                retval += bit_mask;
        }
        // Only shift bit_mask every iteration to maintain alignment
        bit_mask >>= 1;
    }
}
