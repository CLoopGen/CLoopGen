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
    // Variant 2: Reduced computational intensity with simplified logic and modified trip count
    int step = (shift2 > 16) ? 2 : 1; // Increase step size for larger shift2 to reduce effective iterations
    for (i = 0; i < shift2; i += step) {
        guess = retval + (bit_mask >> 1); // Use a shifted version to simplify effect
        accu = (int64_t)guess * guess;
        square = (int)(accu >> bits);     // Removed addition of bit_mask for less computation
        if (x > square)                   // Simplified condition (strict comparison)
            retval += bit_mask;
        bit_mask >>= 2; // Faster reduction of bit_mask to adapt to larger steps
    }
    // Compensate for reduced iterations by final adjustment if needed
    if ((shift2 % 2) && (bit_mask > 0)) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)(accu >> bits);
        if (x >= square)
            retval += bit_mask;
    }
}
