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
    int delayed_retval_update = retval;
    for (i = 0; i < shift2; i++) {
        int next_bit_mask = prev_bit_mask >> 1;
        int adjusted_guess = delayed_retval_update + prev_bit_mask + speculative_add;
        int64_t accu_val = (int64_t)adjusted_guess * adjusted_guess;
        int computed_square = (int)((accu_val + prev_bit_mask) >> bits);
        if (x >= computed_square) {
            speculative_add += prev_bit_mask;
        }
        prev_bit_mask = next_bit_mask;
    }
    retval = delayed_retval_update + speculative_add;
}
