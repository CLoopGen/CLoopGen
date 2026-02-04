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
    int local_bit_mask = bit_mask;
    int local_retval = retval;
    int local_x = x;
    int local_bits = bits;
    
    // Increase arithmetic operations per iteration with redundant computations
    // and reduce effective trip count by skipping every other step
    for (i = 0; i < shift2; i++) {
        // Perform prediction with two candidate guesses per iteration
        int guess1 = local_retval + local_bit_mask;
        int guess2 = local_retval + (local_bit_mask >> 1);

        // Compute squares using int64_t to prevent overflow
        int64_t accu1 = (int64_t)guess1 * guess1;
        int64_t accu2 = (int64_t)guess2 * guess2;

        int square1 = (int)((accu1 + local_bit_mask) >> local_bits);
        int square2 = (int)((accu2 + (local_bit_mask >> 1)) >> local_bits);

        // Conditional update based on both candidates (increased logic density)
        if (local_x >= square1) {
            local_retval += local_bit_mask;
            local_bit_mask >>= 1;
        } else if (local_x >= square2) {
            local_retval += (local_bit_mask >> 1);
            local_bit_mask >>= 2;
            i++; // Compensate for effective larger step
        } else {
            local_bit_mask >>= 2;
            i++; // Skip next iteration due to aggressive masking
        }
    }

    // Write back to global state
    retval = local_retval;
    bit_mask = local_bit_mask;
}
