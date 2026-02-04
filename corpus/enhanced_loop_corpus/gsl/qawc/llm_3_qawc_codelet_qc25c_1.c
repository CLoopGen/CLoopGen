#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cheb12[13];
extern double moment[25];
extern double res12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping array (simulating irregular access pattern)
    static const size_t indices[13] = {0, 2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11}; // Custom permutation of indices
    res12 = 0.0;
    for (i = 0; i < 13; i++) {
        size_t idx = indices[i]; // Indirect access via lookup
        res12 += cheb12[idx] * moment[idx];
    }
}
