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
    guess = retval + bit_mask;
    accu = (int64_t)guess * guess;
    square = (int)((accu + bit_mask) >> bits);
    retval = (x >= square) ? (retval + bit_mask) : retval;
    bit_mask >>= 1;
}
}
