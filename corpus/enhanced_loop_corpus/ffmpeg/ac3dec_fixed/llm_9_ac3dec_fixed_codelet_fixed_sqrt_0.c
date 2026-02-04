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
for (i = 0; i < shift2 * 3; i++) {
    guess = retval + (bit_mask >> 1);
    accu = (int64_t)guess * guess + (int64_t)bit_mask;
    square = (int)((accu + (bit_mask << 1)) >> (bits - 1));
    if (x >= square && (i % 3) == 0)
        retval += (bit_mask >> 1);
    else if (x < square && (i % 3) == 1)
        retval -= (bit_mask >> 2);
    bit_mask >>= 1;
}
}
