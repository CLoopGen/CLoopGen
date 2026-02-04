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
for (int k = 0; k < shift2 * 1; k += 1) { // Depth decreased: ensure flat single loop (already flat, but restructured index)
    i = k; // Map to original i
    guess = retval + bit_mask;
    accu = (int64_t)guess * guess;
    square = (int)((accu + bit_mask) >> bits);
    if (x >= square)
        retval += bit_mask;
    bit_mask >>= 1;
}
}
