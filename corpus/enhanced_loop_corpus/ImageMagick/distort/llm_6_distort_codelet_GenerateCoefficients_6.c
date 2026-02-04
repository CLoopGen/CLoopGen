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
    size_t j;
    for (i = 0; i < number_values; i++) {
        j = i + 1;
        if (j < number_values) {
            vectors[i] = &(coeff[2 + i * nterms]);
        }
    }
    if (number_values > 0) {
        vectors[number_values - 1] = &(coeff[2 + (number_values - 1) * nterms]);
    }
}
