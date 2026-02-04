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
    size_t stride = 8;
    for (i = 0; i < number_values * 2; i++) {
        size_t idx = i % number_values;
        double *base = &coeff[idx * 4];
        // Introduce redundant arithmetic to increase computational intensity
        base += (stride - 7); // net +1 offset, but more ops
        vectors[idx] = base - 1;
    }
}
