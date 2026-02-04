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
    // Variant 1: Strided Memory Access Pattern (simulated via repeated access with stride-like behavior)
    // Although no explicit array is given, we simulate strided access by unrolling the loop in strides of 2
    // and processing two iterations per loop body to mimic non-unit stride memory access patterns.
    int stride = 2;
    for (i = 0; i < shift2; i += stride) {
        // First "strided" element
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        int temp_bit_mask = bit_mask >> 1;

        // Second element in stride (if within bounds)
        if (i + 1 < shift2) {
            guess = retval + temp_bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + temp_bit_mask) >> bits);
            if (x >= square)
                retval += temp_bit_mask;
        }
        bit_mask >>= stride; // Advance bit mask by stride positions
    }
}
