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
    for (i = 0; i < shift2; i++) {
        // Introduce early exit condition based on bit_mask becoming zero
        if (bit_mask == 0) {
            break;
        }
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        // Original condition replaced with unconditional update followed by correction via masking
        int update_val = (x >= square) ? bit_mask : 0;
        retval += update_val;
        bit_mask >>= 1;
    }
}
