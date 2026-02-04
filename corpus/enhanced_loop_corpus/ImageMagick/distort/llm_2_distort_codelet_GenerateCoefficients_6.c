#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_values;
extern double *coeff;
extern size_t i;
extern double **vectors;
extern size_t nterms;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive blocks starting at 2 + i*nterms,
    // we now access elements with a stride of 2, simulating a non-unit stride access pattern.
    // This changes the memory access to every second element starting from the computed base.
    for (i = 0; i < number_values; i++) {
        size_t base_index = 2 + i * nterms;
        // Create a strided view: assume we want to skip every other coefficient
        // We allocate a temporary vector to hold strided data (for realism, though not freed here)
        double *strided_vector = (double*)malloc((nterms / 2) * sizeof(double));
        for (size_t j = 0; j < nterms / 2; j++) {
            strided_vector[j] = coeff[base_index + j * 2];  // Stride of 2
        }
        vectors[i] = strided_vector;
    }
}
