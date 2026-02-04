#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
int m;
double x;
double *result_array;
double *result_deriv_array;
int ell;
double diff_a;
double diff_b;

void init_vars() {
    m = 2;
    lmax = 1000000;
    x = 0.75;
    diff_a = 1.5;
    diff_b = 2.5;

    size_t array_size = (lmax - m + 1) * sizeof(double);
    result_array = (double *)aligned_alloc(32, array_size);
    result_deriv_array = (double *)aligned_alloc(32, array_size);

    for (size_t i = 0; i < lmax - m + 1; i++) {
        result_array[i] = (double)(i + 1) * 0.01;
    }

    for (size_t i = 0; i < lmax - m + 1; i++) {
        result_deriv_array[i] = 0.0;
    }
}