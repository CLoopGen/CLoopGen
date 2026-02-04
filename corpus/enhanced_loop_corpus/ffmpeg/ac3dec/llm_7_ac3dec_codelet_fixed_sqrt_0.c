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
    int prev_bit_mask = bit_mask;
    int prev_retval = retval;
    int next_retval, next_bit_mask;
    for (i = 0; i < shift2; i++) {
        int current_guess = prev_retval + prev_bit_mask;
        int64_t current_accu = (int64_t)current_guess * current_guess;
        int current_square = (int)((current_accu + prev_bit_mask) >> bits);
        next_retval = (x >= current_square) ? prev_retval + prev_bit_mask : prev_retval;
        next_bit_mask = prev_bit_mask >> 1;
        prev_retval = next_retval;
        prev_bit_mask = next_bit_mask;
    }
    retval = prev_retval;
    bit_mask = prev_bit_mask;
}
