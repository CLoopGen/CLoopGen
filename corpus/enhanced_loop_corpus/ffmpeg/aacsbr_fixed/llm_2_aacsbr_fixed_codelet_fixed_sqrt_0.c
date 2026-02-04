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
    // We simulate an array access pattern by treating scalar variables as elements in a logical array
    // and accessing them with a fixed stride. This mimics strided access in data-parallel contexts.
    int *vars[] = {&retval, &bit_mask, &guess, &square}; // Logical array of pointers to tracked scalars
    int n_vars = 4;
    for (i = 0; i < shift2; i++) {
        // Strided access: use modulo arithmetic with stride 2 to access "every other" variable logically
        int idx_guess = (i * 2) % n_vars;
        int idx_square = (i * 2 + 1) % n_vars;
        *(vars[idx_guess]) = retval + bit_mask;
        accu = (int64_t)(*(vars[idx_guess])) * (*(vars[idx_guess]));
        *(vars[idx_square]) = (int)((accu + bit_mask) >> bits);
        if (x >= *(vars[idx_square]))
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
