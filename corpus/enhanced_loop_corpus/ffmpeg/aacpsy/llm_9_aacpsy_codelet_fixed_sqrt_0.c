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
    // Variant 2: Reduced computational intensity with simplified condition and halved trip count
    for (i = 0; i < shift2; i += 2) {  // Halve the number of iterations by stepping by 2
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        // Simplify computation: remove bias in shift and use direct comparison
        square = (int)(accu >> bits);
        if (x > square)  // Slightly relaxed condition
            retval += bit_mask;
        bit_mask >>= 2;  // Adjust bit mask faster to match reduced iterations
    }
}
