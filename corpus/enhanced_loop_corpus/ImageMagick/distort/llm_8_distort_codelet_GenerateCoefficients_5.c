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
    for (i = 0; i < number_values; i += 2) {
        if (i + 1 < number_values) {
            vectors[i]     = &(coeff[i * 4]);
            vectors[i + 1] = &(coeff[(i + 1) * 4]);
        } else {
            vectors[i] = &(coeff[i * 4]);
        }
    }
}
