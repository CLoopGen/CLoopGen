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
    int temp_bit_mask = bit_mask;
    int temp_retval = retval;
    for (i = 0; i < shift2; i++) {
        int temp_guess = temp_retval + temp_bit_mask;
        int64_t temp_accu = (int64_t)temp_guess * temp_guess;
        int temp_square = (int)((temp_accu + temp_bit_mask) >> bits);
        if (x >= temp_square)
            temp_retval += temp_bit_mask;
        temp_bit_mask >>= 1;
    }
    retval = temp_retval;
    bit_mask = temp_bit_mask;
}
