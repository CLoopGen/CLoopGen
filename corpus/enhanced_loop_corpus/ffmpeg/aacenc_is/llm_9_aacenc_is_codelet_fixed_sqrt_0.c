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
    // Variant 2: Reduced arithmetic density and increased trip count via split operations
    // Artificially increase loop iterations and spread computation across more steps
    int extended_shift = shift2 * 2;
    int temp_guess, temp_square;
    int64_t temp_accu;
    for (i = 0; i < extended_shift; i++) {
        // Only perform original logic on even iterations
        if ((i & 1) == 0) {
            temp_guess = retval + bit_mask;
        } else {
            temp_accu = (int64_t)temp_guess * temp_guess;
            temp_square = (int)((temp_accu + bit_mask) >> bits);
            if (x >= temp_square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
