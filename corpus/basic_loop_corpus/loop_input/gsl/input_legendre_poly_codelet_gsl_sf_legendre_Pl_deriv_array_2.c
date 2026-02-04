#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int lmax = 1000000;
double x = 0.5;
double *result_deriv_array;
int ell;

void init_vars() {
    result_deriv_array = (double *)aligned_alloc(32, (lmax + 1) * sizeof(double));
    for (int i = 0; i <= lmax; i++) {
        result_deriv_array[i] = 0.0;
    }
}