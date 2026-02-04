#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
int m;
double *result_array;
int ell;

void init_vars() {
    m = 0;
    lmax = 10000000; // This will make the loop run approximately 10M iterations
    result_array = (double *)calloc(lmax - m + 1, sizeof(double));
}

void loop();