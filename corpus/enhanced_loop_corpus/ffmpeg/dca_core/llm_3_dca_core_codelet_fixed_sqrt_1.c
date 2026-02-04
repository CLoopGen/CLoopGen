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
    // Variant 2: Strided memory access pattern using a larger buffer with stride of 2
    int buffer[128]; // Large enough to allow striding
    const int stride = 2;
    for (i = 0; i < shift2; i++) {
        guess = retval + bit_mask;
        buffer[i * stride] = guess; // Strided write: every 2nd element used
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        buffer[i * stride + 1] = square; // Alternate elements for square
        if (x >= buffer[i * stride + 1])
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
