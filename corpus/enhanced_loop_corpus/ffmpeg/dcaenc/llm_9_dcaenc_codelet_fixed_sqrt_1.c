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
    // Variant 2: Reduced computational intensity with simplified condition and increased loop stride
    // Effectively reduces work per iteration and lowers trip count impact

    int local_retval = retval;
    int local_bit_mask = bit_mask;

    // Loop runs at reduced frequency by stepping every 2 original steps
    for (i = 0; i < shift2; i += 2) {
        // Skip full square computation: use linear approximation instead
        // Approximate effect of (retval + bit_mask)^2 influence without full multiply
        int approx_square = local_retval + local_bit_mask;
        if (x >= approx_square * 2) {  // Heuristic scaling to maintain rough behavior
            local_retval += local_bit_mask;
        }
        local_bit_mask >>= 2;  // Shift by 2 to match stride, reducing total operations
    }

    // Update externs after loop
    retval = local_retval;
    bit_mask = local_bit_mask;
}
