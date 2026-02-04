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

    for (i = 0; i < shift2 && local_bit_mask > 0; i++) {
        int temp_guess = local_retval + local_bit_mask;
        int64_t temp_accu = (int64_t)temp_guess * temp_guess;
        int temp_square = (int)((temp_accu + (local_bit_mask - 1)) >> local_bits);
        
        if (local_x >= temp_square) {
            local_retval += local_bit_mask;
        }
        local_bit_mask >>= 1;
    }

    retval = local_retval;
}
