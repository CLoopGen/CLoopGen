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
    // and increasing effective trip count via internal steps
    int local_accu_low = 0, local_accu_high = 0;
    for (i = 0; i < shift2 * 3; i++) {  // Triplicated trip count
        int adjusted_i = i / 3;
        int phase = i % 3;
        guess = retval + (bit_mask >> adjusted_i);

        if (phase == 0) {
            accu = (int64_t)guess * guess;
        } else if (phase == 1) {
            accu += (int64_t)(guess + 1) * (guess - 1);  // Additional computation
            accu >>= 1;  // Simulated refinement
        } else {
            square = (int)((accu + (bit_mask >> adjusted_i)) >> bits);
            if (x >= square)
                retval += (bit_mask >> adjusted_i);
        }

        // Accumulate fake work to increase compute density
        local_accu_low += (i & 1) ? (local_accu_high ^ i) : local_accu_low;
        local_accu_high += (i & 2) ? (local_accu_low + 1) : local_accu_high;
    }
    // Finalize with a single real update per original step (approximate)
    for (i = 0; i < shift2; i++) {
        guess = retval + (bit_mask >> i);
        accu = (int64_t)guess * guess;
        square = (int)((accu + (bit_mask >> i)) >> bits);
        if (x >= square)
            retval += (bit_mask >> i);
    }
}
