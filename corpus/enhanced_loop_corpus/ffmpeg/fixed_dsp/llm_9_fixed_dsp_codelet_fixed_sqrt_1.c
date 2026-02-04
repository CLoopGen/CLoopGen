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
    // Variant 2: Reduced arithmetic density with intermediate variable reuse and increased trip count
    // Each original iteration is split into two, increasing loop trips but simplifying each
    int double_shift = shift2 << 1;
    int temp_guess;
    int temp_square;
    int64_t temp_accu;

    for (i = 0; i < double_shift; i++) {
        if (i % 2 == 0) {
            // Even step: compute guess and accumulate squared value
            temp_guess = retval + bit_mask;
            temp_accu = (int64_t)temp_guess * temp_guess;
        } else {
            // Odd step: complete comparison and update
            temp_square = (int)((temp_accu + bit_mask) >> bits);
            if (x >= temp_square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
