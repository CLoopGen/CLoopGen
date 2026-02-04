#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 134217728; // Size chosen to process ~256MB of data (134217728 * sizeof(double) ≈ 256MB)
double *result_array;
int j;

void init_vars() {
    result_array = (double *)calloc((size_t)(nmax - nmin + 1), sizeof(double));
    if (!result_array) {
        exit(1);
    }
}