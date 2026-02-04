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
    // Variant 2: Reduced computational intensity with simplified condition and halved effective trip count
    int step = 2;
    int limit = shift2 / 2;

    for (i = 0; i < limit; i += 1) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)(accu >> bits);  // Removed addition of bit_mask for simplicity
        if (x >= square && bit_mask > 1)  // Added early skip condition
            retval += bit_mask;
        bit_mask >>= 2;  // Larger shift to reduce effective iterations
    }
    // Compensate for reduced trip count with a final adjustment if needed
    if (bit_mask == 1 && ((retval + 1) * (retval + 1) <= x))
        retval += 1;
}
