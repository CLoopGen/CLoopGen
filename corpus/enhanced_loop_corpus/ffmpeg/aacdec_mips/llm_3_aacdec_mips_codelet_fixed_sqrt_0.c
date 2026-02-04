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
    // Variant 2: Strided memory access pattern using a precomputed lookup table with stride > 1
    int stride = 2;
    int table_size = (shift2 * stride);
    int* guess_table = (int*)alloca(table_size * sizeof(int));
    int* square_table = (int*)alloca(table_size * sizeof(int));
    int temp_mask = bit_mask;
    // Pre-fill tables with strided writes
    for (i = 0; i < shift2; i++) {
        int idx = i * stride;
        guess_table[idx] = retval + temp_mask;
        int64_t accu_local = (int64_t)guess_table[idx] * guess_table[idx];
        square_table[idx] = (int)((accu_local + temp_mask) >> bits);
        temp_mask >>= 1;
    }
    // Process with same stride
    temp_mask = bit_mask;
    for (i = 0; i < shift2; i++) {
        int idx = i * stride;
        if (x >= square_table[idx])
            retval += temp_mask;
        temp_mask >>= 1;
    }
}
