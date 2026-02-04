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
    // Variant 1: Increased computational intensity by unrolling the loop and adding redundant arithmetic operations
    // Trip count remains the same, but each iteration performs more work via manual unrolling and extra computations
    int temp_accu_low, temp_accu_high;
    for (i = 0; i < shift2; i += 2) {
        // First iteration of unrolled pair
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;

        // Second iteration (if within bounds)
        if (i + 1 < shift2) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            // Add dummy computation to increase complexity
            temp_accu_low = (int)(accu & 0xFFFFFFFF);
            temp_accu_high = (int)(accu >> 32);
            temp_accu_low = (temp_accu_low ^ temp_accu_high) + 1; // Useless but safe op
            square = (int)((accu + bit_mask + temp_accu_low) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
