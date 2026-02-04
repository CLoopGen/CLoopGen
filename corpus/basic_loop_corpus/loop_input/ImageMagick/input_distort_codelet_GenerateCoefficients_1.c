#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

double *coeff;
size_t i;
size_t number_coefficients;

void init_vars() {
    number_coefficients = 134217728; // ~1073 MB of data (134217728 * 8 bytes per double)
    coeff = (double *)calloc(number_coefficients, sizeof(double));
    if (!coeff) {
        exit(1);
    }
}