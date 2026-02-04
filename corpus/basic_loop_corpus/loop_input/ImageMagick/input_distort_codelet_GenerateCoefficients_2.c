#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *arguments;
size_t number_values;
double *coeff;
size_t i;
size_t cp_values;

void init_vars() {
    number_values = 6710886;  // ~204 MB of data (each double is 8 bytes)
    cp_values = 3355443;      // Half of number_values to allow offset access
    size_t coeff_size = number_values * 3 + 2;

    arguments = (double*)aligned_alloc(32, (cp_values + number_values) * sizeof(double));
    coeff = (double*)aligned_alloc(32, coeff_size * sizeof(double));

    if (!arguments || !coeff) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < cp_values + number_values; idx++) {
        arguments[idx] = (double)(idx + 1);
    }
    for (size_t idx = 0; idx < coeff_size; idx++) {
        coeff[idx] = 0.0;
    }
}