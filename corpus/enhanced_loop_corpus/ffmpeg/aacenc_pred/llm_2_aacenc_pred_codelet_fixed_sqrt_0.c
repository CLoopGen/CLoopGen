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
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride
    // We simulate an array of bit masks and results accessed with a fixed stride (e.g., stride of 2)
    // This mimics scenarios where data is not accessed sequentially but in strided fashion
    int bit_mask_arr[32];
    int retval_arr[32];
    
    // Initialize simulated arrays assuming shift2 <= 32
    for (int idx = 0; idx < shift2; idx++) {
        bit_mask_arr[idx] = bit_mask >> idx;
        retval_arr[idx] = retval;
    }

    for (i = 0; i < shift2; i += 2) {  // Stride of 2
        int current_bit_mask = bit_mask_arr[i];
        int current_retval = retval_arr[i];

        guess = current_retval + current_bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + current_bit_mask) >> bits);
        if (x >= square)
            retval += current_bit_mask;

        // Update global bit_mask as side effect (original behavior dependency)
        bit_mask = current_bit_mask >> 1;
    }
    // Final cleanup for any remaining iterations due to stride skip
    for (; i < shift2; i++) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
