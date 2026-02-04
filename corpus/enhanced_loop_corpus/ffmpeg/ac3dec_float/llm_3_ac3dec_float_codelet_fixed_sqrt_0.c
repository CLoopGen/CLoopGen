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
    // Variant 2: Strided memory access pattern with stride of 2 (simulated via index scaling)
    // We simulate accessing elements as if they were stored in an array with stride 2
    int temp_retval = retval;
    int temp_bit_mask = bit_mask;
    for (i = 0; i < shift2; i++) {
        int stride_index = i * 2; // strided access pattern (every second element)
        int effective_guess = temp_retval + (temp_bit_mask >> (stride_index % 8)); // vary based on stride
        int64_t local_accu = (int64_t)effective_guess * effective_guess;
        int adjusted_bits = bits - (stride_index % 4); // vary shift slightly based on stride
        adjusted_bits = adjusted_bits > 0 ? adjusted_bits : bits; // prevent negative shift
        int local_square = (int)((local_accu + temp_bit_mask) >> adjusted_bits);
        if (x >= local_square)
            temp_retval += temp_bit_mask;
        temp_bit_mask >>= 1;
    }
    retval = temp_retval;
    bit_mask = temp_bit_mask;
}
