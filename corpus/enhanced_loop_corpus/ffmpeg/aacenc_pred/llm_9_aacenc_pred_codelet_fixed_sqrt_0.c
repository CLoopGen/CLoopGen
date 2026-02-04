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
int step = 1;
for (i = 0; i < shift2; i += step) {
    guess = retval + (bit_mask >> 1);
    accu = (int64_t)guess * guess;
    square = (int)((accu + bit_mask) >> bits);
    if (x >= square) {
        retval += (bit_mask >> 1);
        step = 2; // Increase computational stride dynamically
    } else {
        step = 1;
    }
    bit_mask >>= 2; // Faster reduction in mask
    if (bit_mask == 0) break;
}
}
