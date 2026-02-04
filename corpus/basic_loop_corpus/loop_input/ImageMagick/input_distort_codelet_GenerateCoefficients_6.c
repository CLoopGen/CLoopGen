#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t number_values = 10000000;
double *coeff;
size_t i;
double **vectors;
size_t nterms = 10;

void init_vars() {
    coeff = (double *)aligned_alloc(32, sizeof(double) * (2 + number_values * nterms));
    vectors = (double **)aligned_alloc(32, sizeof(double *) * number_values);

    for (size_t idx = 0; idx < (2 + number_values * nterms); idx++) {
        coeff[idx] = (double)(idx);
    }

    for (size_t idx = 0; idx < number_values; idx++) {
        vectors[idx] = &(coeff[2 + idx * nterms]);
    }
}