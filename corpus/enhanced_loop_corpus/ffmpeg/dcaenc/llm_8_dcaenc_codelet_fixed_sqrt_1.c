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
    // Variant 1: Increased computational intensity with unrolled operations and doubled effective trip count via half-step iteration
    int temp_bit_mask = bit_mask;
    int temp_retval = retval;
    int temp_x = x;
    int64_t temp_accu;
    int temp_square;

    for (i = 0; i < shift2; i += 2) {
        // First iteration step
        guess = temp_retval + temp_bit_mask;
        temp_accu = (int64_t)guess * guess;
        temp_square = (int)((temp_accu + temp_bit_mask) >> bits);
        if (temp_x >= temp_square)
            temp_retval += temp_bit_mask;
        temp_bit_mask >>= 1;

        // Second iteration step (unrolled), with additional arithmetic to increase intensity
        if (i + 1 < shift2) {
            guess = temp_retval + temp_bit_mask;
            temp_accu = (int64_t)guess * guess + ((int64_t)temp_bit_mask >> 1); // Extra bias in computation
            temp_square = (int)((temp_accu + temp_bit_mask) >> bits);
            if (temp_x >= temp_square)
                temp_retval += temp_bit_mask;
            temp_bit_mask >>= 1;
        }
    }

    // Write back to externs
    retval = temp_retval;
    bit_mask = temp_bit_mask;
}
