#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int lmax;
double x;
double *result_array;
double p_ellm2;
double p_ellm1;
double p_ell;
int ell;

void init_vars() {
    lmax = 50000000;  // Large enough to take ~0.01s
    x = 0.75;
    result_array = (double*)aligned_alloc(32, (lmax + 1) * sizeof(double));
    if (!result_array) {
        exit(1);
    }
    p_ellm2 = 1.0;
    p_ellm1 = x;
    p_ell = 0.0;
    ell = 0;
}