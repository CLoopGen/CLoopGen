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
    // Variant 2: Strided memory access pattern using an artificial stride over a buffer
    int buffer[64]; // Larger buffer to allow strided access
    int stride = 2; // Access every 2nd element
    for (i = 0; i < shift2; i++) {
        int index = i * stride; // Strided index into buffer
        buffer[index] = retval + bit_mask;
        guess = buffer[index];
        accu = (int64_t)guess * guess;
        buffer[index + 1] = (int)((accu + bit_mask) >> bits);
        square = buffer[index + 1];
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
