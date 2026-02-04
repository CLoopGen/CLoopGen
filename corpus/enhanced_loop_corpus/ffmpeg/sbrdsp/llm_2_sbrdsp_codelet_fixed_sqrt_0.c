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
    // We simulate an array access pattern by treating scalar variables as elements of a logical array
    // and stepping through them with a fixed stride, although in practice they are scalars.
    int *vars[] = {&retval, &bit_mask, &guess, &square}; // Logical array of pointers to tracked vars
    int nvars = 4;
    int stride = 2; // Access every second element in a circular fashion

    for (i = 0; i < shift2; i++) {
        // Simulate strided access: indices 0, 2, (4%4)=0, (6%4)=2, etc.
        int idx1 = (0 * stride) % nvars;
        int idx2 = (1 * stride) % nvars;

        *vars[idx1] += *vars[idx2]; // retval += bit_mask (when idx1=0, idx2=2)
        guess = retval + bit_mask;

        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);

        if (x >= square)
            retval += bit_mask;

        bit_mask >>= 1;
    }
}
