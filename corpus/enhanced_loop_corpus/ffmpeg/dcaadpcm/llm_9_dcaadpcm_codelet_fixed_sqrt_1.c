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
    // Variant 2: Reduced computational intensity with simplified logic and increased trip count
    int extended_count = shift2 << 1;  // Double the trip count but simplify per-iteration work
    int temp_bit_mask = 1 << (bits - 1);  // Reset bit mask based on bits
    for (i = 0; i < extended_count; i++) {
        // Simplify condition: only update every other iteration to reduce computation
        if (i % 2 == 0) {
            guess = retval + temp_bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + temp_bit_mask) >> bits);
            if (x >= square)
                retval += temp_bit_mask;
        }
        temp_bit_mask >>= 1;
        if (temp_bit_mask == 0) break;  // Prevent underflow
    }
}
