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
    // Simulate an array access pattern by treating scalar variables as elements of an array with stride
    int *vars[] = {&retval, &bit_mask, &guess, &square};  // Group relevant variables into a pseudo-array
    int stride = 2; // Access every second element in the logical variable array

    for (i = 0; i < shift2; i++) {
        // Strided access: use modulo to stay within bounds
        guess = *(vars[(0 + stride) % 4]) + *(vars[1]);
        accu = (int64_t)guess * guess;
        square = (int)((accu + *(vars[1])) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
