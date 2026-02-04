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
    int speculative_bit_mask = bit_mask;
    int speculative_retval = retval;
    int prev_guess = 0;
    for (i = 0; i < shift2; i++) {
        int current_guess = speculative_retval + speculative_bit_mask;
        int64_t accu_val = (int64_t)current_guess * current_guess;
        int square_val = (int)((accu_val + speculative_bit_mask) >> bits);
        if (x >= square_val) {
            prev_guess = current_guess;
            speculative_retval += speculative_bit_mask;
        } else {
            prev_guess = speculative_retval + (speculative_bit_mask >> 1);
        }
        speculative_bit_mask >>= 1;
    }
    retval = speculative_retval;
    guess = prev_guess;
}
