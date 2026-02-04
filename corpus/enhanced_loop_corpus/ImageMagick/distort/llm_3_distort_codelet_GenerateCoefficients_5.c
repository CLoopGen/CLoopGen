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
    size_t index;
    for (i = 0; i < number_values; i++) {
        index = i * 4;
        vectors[i] = &coeff[index];
    }
}
