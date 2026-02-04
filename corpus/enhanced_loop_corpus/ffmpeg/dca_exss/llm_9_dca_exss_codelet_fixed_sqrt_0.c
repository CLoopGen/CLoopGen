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
    int extended_loop = shift2 << 1;  // Double the trip count but simplify body
    for (i = 0; i < extended_loop; i++) {
        // Remove multiplication and use additive approximation for square
        // Simulate coarse incremental check without full multiplication
        guess = retval + bit_mask;
        // Approximate square using linear step instead of full multiply
        square = retval * 2 + bit_mask;
        if (x >= square) {
            retval += bit_mask;
        }
        // Slow down bit mask decay to accommodate higher loop count
        if ((i & 1) == 1) {  // Only shift every second iteration
            bit_mask >>= 1;
        }
    }
}
