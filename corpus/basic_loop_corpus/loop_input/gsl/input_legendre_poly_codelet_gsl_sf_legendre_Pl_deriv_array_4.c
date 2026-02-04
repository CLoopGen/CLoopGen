#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int lmax;
double x;
double *result_array;
double *result_deriv_array;
int ell;
double diff_a;
double diff_b;

void init_vars() {
    lmax = 20000000;  // Adjusted to achieve ~0.01s runtime on typical modern CPU
    x = 0.5;
    diff_a = 1.0;
    diff_b = 1.0;
    ell = 0;

    result_array = (double*)aligned_alloc(32, (lmax + 1) * sizeof(double));
    result_deriv_array = (double*)aligned_alloc(32, (lmax + 1) * sizeof(double));

    for (int i = 0; i <= lmax; i++) {
        result_array[i] = (double)(i % 100) / 100.0;
    }

    for (int i = 0; i <= lmax; i++) {
        result_deriv_array[i] = 0.0;
    }
}