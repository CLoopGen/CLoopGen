#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double y_out[];
extern double * delta;
extern double * rhs_temp;
extern  double h;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) memory access using an index map
    // Simulates indirect access pattern common in sparse computations
    // Here we assume an implicit index mapping: reverse order access
    for (i = 0; i < dim; i++) {
        size_t j = dim - 1 - i;  // Reverse indexing
        rhs_temp[j] = h * y_out[j] - delta[j];
    }
}
