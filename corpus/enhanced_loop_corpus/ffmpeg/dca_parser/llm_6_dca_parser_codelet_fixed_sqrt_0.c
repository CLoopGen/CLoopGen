#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int shift2;
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_guess, temp_square;
    for (i = 0; i < shift2; i++) {
        temp_guess = retval + bit_mask;
        accu = (int64_t)temp_guess * temp_guess;
        temp_square = (int)((accu + bit_mask) >> bits);
        if (x >= temp_square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
