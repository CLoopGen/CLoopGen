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
if (shift2 > 0) {
    for (i = 0; i < shift2; i += 2) {
        // Unrolled body to simulate deeper logic with conditional handling
        for (int step = 0; step < 2 && (i + step) < shift2; step++) {
            int temp_i = i + step;
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
}
