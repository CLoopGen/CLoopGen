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
    int unroll_factor = 4;

    for (i = 0; i < shift2 - (unroll_factor - 1); i += unroll_factor) {
        guess = local_retval + local_bit_mask;
        local_accu = (int64_t)guess * guess;
        local_square = (int)((local_accu + local_bit_mask) >> local_bits);
        if (local_x >= local_square)
            local_retval += local_bit_mask;
        local_bit_mask >>= 1;

        guess = local_retval + local_bit_mask;
        local_accu = (int64_t)guess * guess;
        local_square = (int)((local_accu + local_bit_mask) >> local_bits);
        if (local_x >= local_square)
            local_retval += local_bit_mask;
        local_bit_mask >>= 1;

        guess = local_retval + local_bit_mask;
        local_accu = (int64_t)guess * guess;
        local_square = (int)((local_accu + local_bit_mask) >> local_bits);
        if (local_x >= local_square)
            local_retval += local_bit_mask;
        local_bit_mask >>= 1;

        guess = local_retval + local_bit_mask;
        local_accu = (int64_t)guess * guess;
        local_square = (int)((local_accu + local_bit_mask) >> local_bits);
        if (local_x >= local_square)
            local_retval += local_bit_mask;
        local_bit_mask >>= 1;
    }

    for (; i < shift2; i++) {
        guess = local_retval + local_bit_mask;
        local_accu = (int64_t)guess * guess;
        local_square = (int)((local_accu + local_bit_mask) >> local_bits);
        if (local_x >= local_square)
            local_retval += local_bit_mask;
        local_bit_mask >>= 1;
    }

    retval = local_retval;
    bit_mask = local_bit_mask;
}
