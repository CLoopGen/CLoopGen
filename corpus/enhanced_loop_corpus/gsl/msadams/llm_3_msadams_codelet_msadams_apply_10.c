#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double * z;
extern size_t ord;
extern size_t i;
extern size_t j;
extern  double hrel;
extern double coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect memory access via an index array (simulated with arithmetic)
    // Simulate precomputed column offsets for indirect-like access (e.g., access in scrambled order: reverse j)
    for (i = 1; i < ord + 1; i++) {
        for (j = 0; j < dim; j++) {
            size_t rev_j = dim - 1 - j;  // reverse access pattern in inner dimension
            size_t idx = i * dim + rev_j;
            z[idx] *= coeff;
        }
        coeff *= hrel;
    }
}
