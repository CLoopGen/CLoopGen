#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_values;
extern double *coeff;
extern size_t i;
extern double **vectors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    double *temp;
    for (j = 0; j < number_values; j++) {
        temp = &(coeff[j * 3]);
        vectors[j] = temp;
    }
}
