#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
double *result_array;
int ell;

void init_vars() {
    lmax = 10000000;  // Adjusted to ensure loop runs ~0.01 seconds
    result_array = (double*)calloc(lmax + 1, sizeof(double));
}

void loop();