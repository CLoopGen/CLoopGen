#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax = 1000000;
double x = 1.5;
double *result_array;
int ell;
double kellp1;
double kell;
double kellm1;

void init_vars() {
    result_array = (double *)calloc(lmax + 2, sizeof(double));
    if (!result_array) {
        exit(1);
    }

    ell = 0;
    kellp1 = 0.0;
    kell = 1.0;
    kellm1 = 0.5;

    for (int i = 0; i <= lmax + 1; i++) {
        result_array[i] = 0.0;
    }
}