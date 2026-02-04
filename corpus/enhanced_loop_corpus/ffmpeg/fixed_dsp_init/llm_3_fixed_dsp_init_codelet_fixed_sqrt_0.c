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
    // Variant 2: Strided memory access pattern using indirect indexing with step > 1
    // Use an index array to create non-consecutive, strided access to data
    int vars[8]; // Expanded array to allow strided access (every 2nd element)
    int indices[4]; // Index mapping: simulate irregular access pattern

    // Map: indices[0] -> retval, indices[1] -> bit_mask, indices[2] -> x, indices[3] -> bits
    indices[0] = 0; indices[1] = 2; indices[2] = 4; indices[3] = 6;

    vars[indices[0]] = retval;      // stride 2 access
    vars[indices[1]] = bit_mask;
    vars[indices[2]] = x;
    vars[indices[3]] = bits;

    int local_shift = shift2;

    for (i = 0; i < local_shift; i++) {
        int temp_guess = vars[indices[0]] + vars[indices[1]];
        accu = (int64_t)temp_guess * temp_guess;
        int temp_square = (int)((accu + vars[indices[1]]) >> vars[indices[3]]);
        if (vars[indices[2]] >= temp_square)
            vars[indices[0]] += vars[indices[1]];
        vars[indices[1]] >>= 1;
    }

    // Write back to global state
    retval = vars[indices[0]];
    bit_mask = vars[indices[1]];
}
