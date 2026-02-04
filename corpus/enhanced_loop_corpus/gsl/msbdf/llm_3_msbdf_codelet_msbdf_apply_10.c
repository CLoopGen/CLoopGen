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
    // Variant 2: Strided memory access — access every 'ord'-th element in a column-wise fashion
    // Interpret z as storing columns of size (ord+1), and process one column index across all rows
    for (j = 0; j < dim; j++) {
        for (i = 1; i < ord + 1; i++) {
            z[i * dim + j] *= coeff;
        }
        coeff *= hrel; // coeff updated per column, preserving original semantic
    }
}
