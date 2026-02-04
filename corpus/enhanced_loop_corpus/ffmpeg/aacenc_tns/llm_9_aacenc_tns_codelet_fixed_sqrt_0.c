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
    // Variant 2: Reduced computational intensity with coalesced conditionals and halved trip count
    // Merge two iterations into one by pre-shifting bit_mask twice, reducing loop overhead
    int temp_retval = retval;
    int current_mask = bit_mask;
    int step;

    for (i = 0; i < shift2; i += 2) {
        // Process two bit positions at once if possible
        int mask1 = current_mask;
        int mask2 = current_mask >> 1;

        // First update
        guess = temp_retval + mask1;
        accu = (int64_t)guess * guess;
        square = (int)((accu + mask1) >> bits);
        if (x >= square)
            temp_retval += mask1;

        // Second update only if not exceeding loop bound
        if ((i + 1) < shift2) {
            guess = temp_retval + mask2;
            accu = (int64_t)guess * guess;
            square = (int)((accu + mask2) >> bits);
            if (x >= square)
                temp_retval += mask2;
        }

        current_mask >>= 2; // Advance two bit positions
    }

    retval = temp_retval;
    bit_mask = current_mask;
}
