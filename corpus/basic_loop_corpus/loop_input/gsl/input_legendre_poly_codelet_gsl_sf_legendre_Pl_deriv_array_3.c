#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int lmax;
double x;
double *result_deriv_array;
int ell;

void init_vars() {
    x = 0.5;
    lmax = 20000000;
    result_deriv_array = (double*)aligned_alloc(32, (lmax + 1) * sizeof(double));
    for (int i = 0; i <= lmax; i++) {
        result_deriv_array[i] = 0.0;
    }
}