#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t number_values;
double *coeff;
size_t i;
double **vectors;

void init_vars() {
    number_values = 64 * 1024 * 1024 / sizeof(double); // ~512MB of coeff data
    coeff = (double *)aligned_alloc(32, number_values * 3 * sizeof(double));
    vectors = (double **)aligned_alloc(32, number_values * sizeof(double*));

    if (!coeff || !vectors) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < number_values * 3; i++) {
        coeff[i] = (double)(i + 1);
    }

    for (i = 0; i < number_values; i++) {
        vectors[i] = &(coeff[i * 3]);
    }
}