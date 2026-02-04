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
    int temp_x = x;
    for (i = 0; i < shift2; i++) {
        int adjusted_bit_mask = bit_mask >> i;
        int trial_val = retval + adjusted_bit_mask;
        int64_t accu_high = (int64_t)trial_val * trial_val;
        int computed_square = (int)((accu_high + adjusted_bit_mask) >> bits);
        speculative_add |= (temp_x >= computed_square) ? adjusted_bit_mask : 0;
    }
    retval += speculative_add;
}
