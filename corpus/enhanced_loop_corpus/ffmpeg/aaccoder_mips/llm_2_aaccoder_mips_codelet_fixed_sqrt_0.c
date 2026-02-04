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
    // Variant 1: Consecutive memory access pattern using array indexing with stride of 1
    // Simulate array-like access by treating scalar variables as elements of an unfolded array
    // Introduce dummy arrays to demonstrate consecutive access, while preserving original logic
    
    int temp_array[4];  // To simulate structured memory layout
    for (i = 0; i < shift2; i++) {
        temp_array[0] = retval;
        temp_array[1] = bit_mask;
        temp_array[2] = x;
        temp_array[3] = bits;

        guess = temp_array[0] + temp_array[1];
        accu = (int64_t)guess * guess;
        square = (int)((accu + temp_array[1]) >> temp_array[3]);
        if (temp_array[2] >= square)
            retval += temp_array[1];
        bit_mask >>= 1;
    }
}
