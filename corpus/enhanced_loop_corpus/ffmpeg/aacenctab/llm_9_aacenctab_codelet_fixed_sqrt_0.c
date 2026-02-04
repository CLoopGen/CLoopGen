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
    // Variant 2: Reduced computational complexity with simplified condition and halved effective trip count
    // Eliminates some arithmetic expressions and uses a step increment to reduce iterations.
    // Maintains functional similarity but lowers operation count per iteration.

    for (i = 0; i < shift2; i += 2) {  // Effectively halves the number of iterations processed
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        // Simplified square approximation: remove bias term (bit_mask) from shift
        square = (int)(accu >> bits);
        if (x >= square) {
            retval += bit_mask;
        }
        bit_mask >>= 2;  // Match step size to maintain rough progress
        if (bit_mask == 0) break;  // Prevent underflow
    }
    // Compensate for possible skipped final step
    if (bit_mask == 0 && (retval + 1) * (retval + 1) <= x) {
        retval += 1;
    }
}
