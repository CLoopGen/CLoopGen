#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t number_values;
double *coeff;
size_t i;
double **vectors;

void init_vars() {
    number_values = 64 * 1024 * 1024 / sizeof(double); // ~512MB total data target, adjusted for double size
    if (number_values > (SIZE_MAX / (4 * sizeof(double)))) {
        number_values = SIZE_MAX / (4 * sizeof(double));
    }

    coeff = (double *)aligned_alloc(32, number_values * 4 * sizeof(double));
    vectors = (double **)aligned_alloc(32, number_values * sizeof(double *));

    if (!coeff || !vectors) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < number_values * 4; j++) {
        coeff[j] = (double)(j + 1);
    }

    for (size_t j = 0; j < number_values; j++) {
        vectors[j] = &(coeff[j * 4]);
    }
}