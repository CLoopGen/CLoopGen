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
    int local_x = x;
    int local_bits = bits;
    int local_bit_mask = bit_mask;
    int local_retval = retval;
    for (i = 0; i < shift2; i++) {
        int local_guess = local_retval + local_bit_mask;
        int64_t local_accu = (int64_t)local_guess * local_guess;
        int local_square = (int)((local_accu + local_bit_mask) >> local_bits);
        // Introduced RAW dependency: use updated local_retval immediately
        local_retval = (local_x >= local_square) ? local_retval + local_bit_mask : local_retval;
        // Removed loop-carried dependency on bit_mask by using shifted value directly in next iteration
        local_bit_mask >>= 1;
    }
    // Final update to global state
    retval = local_retval;
}
