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
    for (j = 1; j <= number_values; j++) {
        vectors[j - 1] = &(coeff[(j - 1) * 3]);
    }
}
