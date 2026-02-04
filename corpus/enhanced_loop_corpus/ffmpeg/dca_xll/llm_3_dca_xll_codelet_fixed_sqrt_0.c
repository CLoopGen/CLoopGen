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
    // Variant 2: Consecutive access simulation using a temporary array to stage bit_mask values
    // Precompute bit_mask sequence into an array to enforce consecutive memory access pattern
    int temp_masks[32];  // Assuming maximum shift2 is 32 for typical bit operations
    int temp_vals[32];
    int count = 0;
    int bm_temp = bit_mask;
    
    // Pre-fill the mask array with consecutive bit shifts
    while (count < shift2 && bm_temp != 0) {
        temp_masks[count] = bm_temp;
        bm_temp >>= 1;
        count++;
    }

    // Use consecutive array access in loop
    for (i = 0; i < shift2 && i < 32; i++) {
        guess = retval + temp_masks[i];
        accu = (int64_t)guess * guess;
        square = (int)((accu + temp_masks[i]) >> bits);
        if (x >= square)
            retval += temp_masks[i];
    }
}
