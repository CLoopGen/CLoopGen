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
    int updated_retval = retval;
    int delayed_write_square = 0;
    int64_t accu_buffer = 0;
    for (i = 0; i < shift2; i++) {
        int next_bit_mask = prev_bit_mask >> 1;
        int speculative_guess = updated_retval + prev_bit_mask;
        int64_t speculative_accu = (int64_t)speculative_guess * speculative_guess;
        int speculative_square = (int)((speculative_accu + prev_bit_mask) >> bits);
        if (i > 0) {
            if (x >= delayed_write_square)
                updated_retval += prev_bit_mask;
        }
        delayed_write_square = speculative_square;
        accu_buffer = speculative_accu;
        prev_bit_mask = next_bit_mask;
    }
    if (x >= delayed_write_square)
        updated_retval += bit_mask >> shift2;
    retval = updated_retval;
}
