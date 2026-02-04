#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double * z;
extern size_t ord;
extern size_t i;
extern size_t j;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to strided access with step of 2, unrolling the inner loop by factor 2
    // This modifies the access to z to be non-consecutive, accessing every other element in dim
    for (i = 1; i < ord + 1; i++)
        for (j = ord; j > i - 1; j--)
            for (k = 0; k < dim; k += 2) {
                if (k + 1 < dim) {
                    z[(j - 1) * dim + k] += z[j * dim + k];
                    z[(j - 1) * dim + k + 1] += z[j * dim + k + 1];
                } else {
                    z[(j - 1) * dim + k] += z[j * dim + k];
                }
            }
}
