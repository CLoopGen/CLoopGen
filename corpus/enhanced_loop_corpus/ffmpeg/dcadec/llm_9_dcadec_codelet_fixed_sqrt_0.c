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
    // Increase computational intensity by adding redundant but safe arithmetic
    // and modifying trip count scaling
    int local_accu_low = (int)(accu & 0xFFFFFFFF);
    int local_accu_high = (int)(accu >> 32);
    for (i = 0; i < (shift2 >> 1); i++) {  // Reduce effective trip count by half
        // Add extra arithmetic operations to increase compute load
        guess = retval + (bit_mask << 1) - (bit_mask >> 1);
        accu = (int64_t)guess * guess + (local_accu_low ^ local_accu_high);
        // Introduce additional shift and masking logic
        square = (int)(((accu + (bit_mask << 2)) >> (bits - 1)) >> 1);

        if (x >= square) {
            retval += bit_mask;
            // Extra update to local state to simulate data dependency
            local_accu_low = (local_accu_low + guess) % 1000;
        }

        // Slower decay of bit_mask with added computation
        bit_mask = (bit_mask >> 1) | (local_accu_high & 1 ? (1 << (bits - 1)) : 0);
        
        // Update helper variables to maintain realism
        local_accu_high = (int)(accu >> 32);
    }
    // Final cleanup pass with original logic if needed (not required per instructions)
}
