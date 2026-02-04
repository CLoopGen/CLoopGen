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
    // Variant 1: Consecutive memory access by reordering computation to traverse z in row-major order
    double *z_ptr = z + dim; // Start at z[1 * dim]
    for (i = 1; i < ord + 1; i++) {
        for (j = 0; j < dim; j++) {
            *z_ptr++ *= coeff;
        }
        coeff *= hrel;
    }
}
