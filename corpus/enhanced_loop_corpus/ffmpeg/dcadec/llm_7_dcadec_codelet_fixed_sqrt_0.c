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
    int prev_bit_mask = bit_mask;
    for (i = 0; i < shift2; i++) {
        int next_bit_mask = speculative_bit_mask >> 1;
        int combined_val = speculative_retval + speculative_bit_mask;
        int64_t accu_val = (int64_t)combined_val * combined_val;
        int normalized_square = (int)((accu_val + speculative_bit_mask) >> bits);
        if (i > 0 && x >= normalized_square)
            speculative_retval += prev_bit_mask;
        prev_bit_mask = speculative_bit_mask;
        speculative_bit_mask = next_bit_mask;
    }
    if (x >= (int)((int64_t)speculative_retval * speculative_retval >> bits))
        retval = speculative_retval;
    else
        retval = retval;
}
