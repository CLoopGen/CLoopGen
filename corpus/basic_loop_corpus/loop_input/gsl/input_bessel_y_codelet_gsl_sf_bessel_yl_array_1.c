#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int lmax;
double x;
double *result_array;
double yellp1;
double yell;
double yellm1;
int ell;

void init_vars() {
    lmax = 10000000;  // Adjusted to achieve ~0.01 sec runtime
    x = 2.0;
    yell = 1.0;
    yellm1 = 0.5;
    yellp1 = 0.0;
    ell = 0;

    result_array = (double*)malloc((lmax + 2) * sizeof(double));
    if (!result_array) {
        exit(1);
    }

    result_array[0] = yellm1;
    result_array[1] = yell;
}