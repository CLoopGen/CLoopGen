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
    int prev_guess = 0;
    int64_t prev_accu = 0;
    for (i = 0; i < shift2; i++) {
        int current_guess = speculative_retval + speculative_mask;
        int64_t current_accu = (int64_t)current_guess * current_guess;
        int current_square = (int)((current_accu + speculative_mask) >> bits);
        if (x >= current_square) {
            speculative_retval += speculative_mask;
        }
        prev_guess = current_guess;
        prev_accu = current_accu;
        speculative_mask >>= 1;
    }
    retval = speculative_retval;
    guess = prev_guess;
    accu = prev_accu;
}
