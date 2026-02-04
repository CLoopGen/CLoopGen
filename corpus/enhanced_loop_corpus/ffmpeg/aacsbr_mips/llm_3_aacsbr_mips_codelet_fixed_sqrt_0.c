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
    // Variant 2: Consecutive access simulation using a local array to stage bit_mask updates
    // Introduce a small buffer to precompute and sequentially consume bit_mask values
    int buffer[32]; // Assuming shift2 <= 32
    int buf_idx = 0;
    int temp_mask = bit_mask;
    int len = shift2;

    // Precompute bit_mask sequence into a consecutive memory layout
    for (int j = 0; j < len && buf_idx < 32; j++, buf_idx++) {
        buffer[buf_idx] = temp_mask;
        temp_mask >>= 1;
    }

    // Now traverse the precomputed values with consecutive memory access pattern
    for (i = 0; i < len; i++) {
        bit_mask = buffer[i]; // Consecutive fetch from array
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
    }
}
