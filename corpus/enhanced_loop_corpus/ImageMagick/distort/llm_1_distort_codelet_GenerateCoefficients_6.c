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
    if (number_values > 0) {
        i = 0;
        for (; i < number_values; i++) {
            vectors[i] = &(coeff[2 + i * nterms]);
        }
    }
}
