#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax = 10000000;
double x = 1.5;
double *result_array;
double jellp1 = 1.0;
double jell = 0.5;
double jellm1;
int ell;

void init_vars() {
    result_array = (double *)aligned_alloc(32, lmax * sizeof(double));
    if (!result_array) {
        exit(1);
    }
}