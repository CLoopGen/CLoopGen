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
    if (ord == 0) return;
    for (i = 1; i <= ord; i++) {
        for (j = 0; j < dim; j++) {
            z[i * dim + j] *= coeff;
        }
        coeff *= hrel;
    }
}
