#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax = 1000000;
double x = 1.5;
double *result_array;
int ell;
double iellp1 = 1.0;
double iell = 2.0;
double iellm1;

void init_vars() {
    result_array = (double*)aligned_alloc(32, lmax * sizeof(double));
    if (!result_array) {
        exit(1);
    }
}