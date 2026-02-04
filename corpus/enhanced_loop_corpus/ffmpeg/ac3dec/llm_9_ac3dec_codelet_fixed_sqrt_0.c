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
    // Variant 2: Reduced computational intensity with simplified condition and increased effective trip count
    int extended_shift = shift2 << 1;  // Double the loop iterations
    for (i = 0; i < extended_shift; i++) {
        // Simplify computation: remove multiplication and use additive approximation
        // Simulate coarse estimation of square using linear step
        guess = retval + (bit_mask >> 1);  // Smaller incremental guess
        // Approximate square without full 64-bit multiply
        square = retval * retval + ((retval << 1) & ~3) + (bit_mask >> 2);
        
        if (x >= square) {
            retval += (bit_mask >> 1);
        }
        // Slower decay of bit_mask to accommodate more iterations
        if ((i & 3) == 3) {  // Only shift every 4th iteration
            bit_mask >>= 1;
        }
    }
}
