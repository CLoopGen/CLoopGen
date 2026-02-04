#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    size_t indices[] = {1, 3, 5, 7, 9, 11}; // Custom indirect access pattern
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    
    for (i = 0; i < num_indices; i++) {
        cheb12[indices[i]] *= 1. / 6.;
    }
}
