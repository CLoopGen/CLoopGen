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
for (i = 0; i < shift2 && bit_mask > 0; i++) {
    guess = retval + (bit_mask << 1);
    accu = (int64_t)guess * guess;
    square = (int)((accu + bit_mask) >> bits);
    if (x >= square) {
        retval += bit_mask << 1;
    } else {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
    }
    bit_mask >>= 2;
    i++; // Compensate for reduced trip count due to higher step in effective operations
}
}
