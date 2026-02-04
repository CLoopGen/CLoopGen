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
    for (i = 0; i < number_values * 2; i++) {
        size_t idx = i / 2;
        vectors[idx] = &(coeff[idx * 3]);
    }
}
