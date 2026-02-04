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
    // Variant 1: Consecutive memory access pattern using array-like indexing with stride of 1
    // Simulate consecutive access by unrolling the effect over a virtual array (using offset)
    int temp_retval = retval;
    int temp_bit_mask = bit_mask;
    for (i = 0; i < shift2; i++) {
        int offset = i; // consecutive access index
        int local_guess = temp_retval + temp_bit_mask;
        int64_t local_accu = (int64_t)local_guess * local_guess;
        int local_square = (int)((local_accu + temp_bit_mask) >> bits);
        if (x >= local_square)
            temp_retval += temp_bit_mask;
        temp_bit_mask >>= 1;
        // Use offset to simulate data access in order (e.g., could index an array in real use)
        // Here, we just maintain correctness via scalar evolution
    }
    retval = temp_retval;
    bit_mask = temp_bit_mask;
}
