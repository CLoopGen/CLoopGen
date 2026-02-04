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
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride of 2
    // We simulate an array access pattern by treating scalar variables as elements of a logical array
    // and accessing them with a fixed stride, although they are not true arrays.
    int *vars[] = {&retval, &bit_mask, &guess, &square}; // Logical array of pointers to tracked vars
    int stride = 2; // Access every second element in the logical array
    for (i = 0; i < shift2; i++) {
        // Strided access: use modulo to stay within bounds
        guess = *(vars[(0 * stride) % 4]) + *(vars[(1 * stride) % 4]); // retval + bit_mask
        accu = (int64_t)guess * guess;
        square = (int)((accu + *(vars[(1 * stride) % 4])) >> bits); // bit_mask used in shift
        if (x >= square)
            retval += *(vars[(1 * stride) % 4]); // bit_mask update
        bit_mask >>= 1;
    }
}
