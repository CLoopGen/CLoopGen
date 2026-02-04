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
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride of 2
    // We simulate an array access pattern by treating 'bit_mask' as part of a virtual array accessed with stride
    int stride = 2;
    int temp_retval[64];  // Simulated array for storing intermediate retval states
    int temp_bit_mask[64]; // Simulated array for bit_mask history

    temp_retval[0] = retval;
    temp_bit_mask[0] = bit_mask;

    for (i = 0; i < shift2; i += stride) {
        // Strided access: only even indices are updated, simulating non-consecutive memory usage
        int idx = i * stride; // Strided index calculation
        if (idx >= 64) break;

        temp_retval[idx] = temp_retval[idx - stride] + temp_bit_mask[idx - stride];
        accu = (int64_t)temp_retval[idx] * temp_retval[idx];
        square = (int)((accu + temp_bit_mask[idx - stride]) >> bits);
        
        if (x >= square)
            retval = temp_retval[idx];
        else
            retval = temp_retval[idx - stride];

        temp_bit_mask[idx] = temp_bit_mask[idx - stride] >> 1;
    }
}
