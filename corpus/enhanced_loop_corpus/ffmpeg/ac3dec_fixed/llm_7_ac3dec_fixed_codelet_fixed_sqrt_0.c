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
    int speculative_retval = retval;
    int speculative_mask = bit_mask;
    for (i = 0; i < shift2; i++) {
        int next_mask = speculative_mask >> 1;
        int adjusted_square;
        int64_t accu_val;
        int trial_guess = speculative_retval + speculative_mask;
        accu_val = (int64_t)trial_guess * trial_guess;
        adjusted_square = (int)((accu_val + speculative_mask) >> bits);
        if (x >= adjusted_square)
            speculative_retval += speculative_mask;
        speculative_mask = next_mask;
    }
    retval = speculative_retval;
    bit_mask = speculative_mask;
}
