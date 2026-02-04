#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *coeff;
extern size_t i;
extern size_t number_coefficients;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(number_coefficients * sizeof(size_t));
    if (!indices) return;
    for (size_t idx = 0; idx < number_coefficients; idx++)
        indices[idx] = idx;
    for (size_t idx = 0; idx < number_coefficients; idx++)
        coeff[indices[idx]] = 0.;
    free(indices);
}
