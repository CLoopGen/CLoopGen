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
    // Variant 1: Strided memory access pattern simulation via index scaling
    // Although no explicit array is given, we simulate a strided access effect by unrolling and stepping with stride-like logic.
    // Here, we process two iterations per loop step (strided by 2), assuming shift2 is even for simplicity.
    int stride = 2;
    for (i = 0; i < shift2; i += stride) {
        // First virtual "strided" element
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;

        // Second element in stride, if within bounds
        if (i + 1 < shift2) {
            guess = retval + bit_mask;
            accu = (int64_t)guess * guess;
            square = (int)((accu + bit_mask) >> bits);
            if (x >= square)
                retval += bit_mask;
            bit_mask >>= 1;
        }
    }
}
