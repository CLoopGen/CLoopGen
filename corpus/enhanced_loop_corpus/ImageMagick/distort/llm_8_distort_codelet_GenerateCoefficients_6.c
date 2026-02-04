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
    for (i = 0; i < number_values; i += 2) {
        if (i + 1 < number_values) {
            vectors[i]     = &(coeff[2 + i * nterms]);
            vectors[i + 1] = &(coeff[2 + (i + 1) * nterms]);
        } else {
            vectors[i] = &(coeff[2 + i * nterms]);
        }
    }
}
