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
for (i = 1; i < ord + 1; i++)
    for (j = ord; j > i - 1; j--) {
        double *z_j_dim = &z[j * dim];
        double *z_j_minus_1_dim = &z[(j - 1) * dim];
        for (k = 0; k < dim; k++) {
            z_j_minus_1_dim[k] += z_j_dim[k];
        }
    }
}
