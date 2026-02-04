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
    int speculative_add = 0;
    int prev_bit_mask = bit_mask;
    int updated_retval = retval;
    for (i = 0; i < shift2; i++) {
        int alt_guess = updated_retval + prev_bit_mask + speculative_add;
        int64_t alt_accu = (int64_t)alt_guess * alt_guess;
        int alt_square = (int)((alt_accu + prev_bit_mask) >> bits);
        speculative_add = (x >= alt_square) ? 0 : -prev_bit_mask;
        updated_retval += (x >= alt_square) ? prev_bit_mask : 0;
        prev_bit_mask >>= 1;
    }
    retval = updated_retval;
}
