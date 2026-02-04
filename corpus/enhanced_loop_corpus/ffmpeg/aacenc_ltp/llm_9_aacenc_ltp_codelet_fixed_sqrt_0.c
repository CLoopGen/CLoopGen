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
    int64_t local_accu;
    int local_square;

    // Increased computational intensity: reduce trip count but increase operations per iteration
    for (i = 0; i < shift2 / 3 + 1; i++) {
        // Perform three logical steps with complex dependencies
        for (int j = 0; j < 3 && (i * 3 + j) < shift2; j++) {
            guess = local_retval + local_bit_mask;
            local_accu = (int64_t)guess * guess;
            local_square = (int)((local_accu + local_bit_mask - (local_accu >> (bits - 4))) >> local_bits);
            if (local_x >= local_square + (local_bit_mask & 0x3)) // Modified condition with extra term
                local_retval += local_bit_mask;
            local_bit_mask >>= 1;
        }
    }

    // Write back to global state
    retval = local_retval;
    bit_mask = local_bit_mask;
}
