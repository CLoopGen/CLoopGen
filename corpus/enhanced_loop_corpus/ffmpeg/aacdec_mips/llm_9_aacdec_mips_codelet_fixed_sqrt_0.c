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
    int local_bit_mask = bit_mask;
    int local_retval = retval;
    int trip_count = shift2 >> 1; // Reduce effective trip count by half

    for (i = 0; i < trip_count; i++) {
        // Combine operations and reduce arithmetic steps
        guess = local_retval + (local_bit_mask >> i); // Introduce index-dependent shift
        accu = (int64_t)guess * guess;
        square = (int)(accu >> bits); // Removed addition of bit_mask for simplicity
        if (x >= square) {
            local_retval += (local_bit_mask >> i);
        }
    }

    // Final update to global state
    retval = local_retval;
    bit_mask = local_bit_mask >> trip_count;
}
