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
    // Variant 2: Reduced arithmetic density by removing intermediate variables and simplifying computation per iteration
    // Also reduces effective trip count by skipping every other iteration
    for (i = 0; i < shift2; i += 2) {
        // Merge guess, square computation and update in fewer steps
        accu = (int64_t)(retval + bit_mask) * (retval + bit_mask);
        if (x >= (int)((accu + bit_mask) >> bits))
            retval += bit_mask;
        bit_mask >>= 2; // Adjust twice as fast to match reduced iterations
    }
    // Compensate for possible leftover iteration when shift2 is odd
    if (shift2 % 2 == 1 && bit_mask > 0) {
        accu = (int64_t)(retval + bit_mask) * (retval + bit_mask);
        if (x >= (int)((accu + bit_mask) >> bits))
            retval += bit_mask;
    }
}
