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
    int64_t prev_accu = 0;
    int prev_square = 0;
    for (i = 0; i < shift2; i++) {
        int combined_val = speculative_retval + speculative_mask;
        int64_t current_accu = (int64_t)combined_val * combined_val;
        int current_square = (int)((current_accu + speculative_mask) >> bits);
        
        if (i > 0 && x >= prev_square) {
            speculative_retval += (speculative_mask << 1);
        }
        
        prev_accu = current_accu;
        prev_square = current_square;
        speculative_mask >>= 1;
    }
    
    if (shift2 > 0 && x >= prev_square)
        speculative_retval += bit_mask >> shift2;
    
    retval = speculative_retval;
}
