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
for (i = 1; i < ord + 1; i += 2) {
    double temp_coeff1 = coeff * hrel;
    double temp_coeff2 = coeff * hrel * hrel;
    size_t idx1, idx2;
    for (j = 0; j < dim; j++) {
        idx1 = i * dim + j;
        z[idx1] *= temp_coeff1;
        if (i + 1 < ord + 1) {
            idx2 = (i + 1) * dim + j;
            z[idx2] *= temp_coeff2;
        }
    }
    coeff *= hrel * hrel;
}
}
