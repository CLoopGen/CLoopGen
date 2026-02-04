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
    // Variant 1: Change memory access pattern to strided access (stride of 2, wrapping if needed)
    for (i = 1; i < ord + 1; i++) {
        for (j = 0; j < dim; j += 2) {
            size_t idx1 = i * dim + j;
            z[idx1] *= coeff;
            // Handle wrap-around for odd-sized dim if necessary
            if (j + 1 < dim) {
                size_t idx2 = i * dim + j + 1;
                z[idx2] *= coeff;
            }
        }
        coeff *= hrel;
    }
}
