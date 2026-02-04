#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int lmax;
int m;
double x;
double *result_deriv_array;
int ell;

void init_vars() {
    m = 2;
    lmax = 1000000;
    x = 1.5;
    size_t array_size = (lmax - m + 1) * sizeof(double);
    result_deriv_array = (double *)aligned_alloc(32, array_size);
    for (size_t i = 0; i < (lmax - m + 1); i++) {
        result_deriv_array[i] = 0.0;
    }
}