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



void loop() {
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride
    // Here, we simulate a strided access by treating 'bit_mask' and related variables as elements of an array
    // accessed with a fixed stride (e.g., every second element in a logical sequence)
    int stride = 2;
    int max_iter = shift2 / stride;

    for (i = 0; i < max_iter; i++) {
        int idx = i * stride;  // Strided index
        int local_bit_mask = bit_mask >> idx;  // Simulate accessing "bit_mask_array[idx]"
        guess = retval + local_bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + local_bit_mask) >> bits);
        if (x >= square)
            retval += local_bit_mask;
    }
}
