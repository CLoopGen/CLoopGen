#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int shift2;
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access pattern using array-like indexing (simulated via pointer arithmetic)
    int* restrict ret_ptr = &retval;
    int* restrict mask_ptr = &bit_mask;
    int temp_array[32]; // Simulated working array to enable consecutive access
    for (int idx = 0; idx < shift2; idx++) {
        int guess_val = ret_ptr[0] + mask_ptr[0];
        int64_t accu_val = (int64_t)guess_val * guess_val;
        int square_val = (int)((accu_val + mask_ptr[0]) >> bits);
        temp_array[idx] = square_val; // Store in consecutive memory
        if (x >= temp_array[idx])
            ret_ptr[0] += mask_ptr[0];
        mask_ptr[0] >>= 1;
    }
}
