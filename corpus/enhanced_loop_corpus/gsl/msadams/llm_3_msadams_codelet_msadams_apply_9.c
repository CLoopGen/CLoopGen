#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double * z;
extern double * l;
extern size_t ord;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use a stride of 'dim' and access columns through pointers advanced by steps
    double *z_target;
    const double *z_source = &z[(ord + 1) * dim];
    for (i = 2; i < ord + 1; i++) {
        z_target = &z[i * dim]; // Row start for target
        double factor = -l[i];
        for (j = 0; j < dim; j += 4) { // Unroll by 4 for strided access (SIMD-like pattern)
            if (j + 0 < dim) z_target[j + 0] += factor * z_source[j + 0];
            if (j + 1 < dim) z_target[j + 1] += factor * z_source[j + 1];
            if (j + 2 < dim) z_target[j + 2] += factor * z_source[j + 2];
            if (j + 3 < dim) z_target[j + 3] += factor * z_source[j + 3];
        }
    }
}
