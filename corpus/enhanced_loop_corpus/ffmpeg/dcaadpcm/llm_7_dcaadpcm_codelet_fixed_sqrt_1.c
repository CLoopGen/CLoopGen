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
    for (i = 0; i < shift2; i++) {
        int guess = speculative_retval + speculative_bit_mask;
        int64_t accu = (int64_t)guess * guess;
        int square = (int)((accu + speculative_bit_mask) >> bits);
        if (x >= square)
            speculative_retval += speculative_bit_mask;
        speculative_bit_mask >>= 1;
    }
    // Update shared state only after loop completes
    retval = speculative_retval;
    bit_mask = speculative_bit_mask;
}
