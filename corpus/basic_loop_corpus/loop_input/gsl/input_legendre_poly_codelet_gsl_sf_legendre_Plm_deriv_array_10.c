#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
int m;
double *result_deriv_array;
int ell;

void init_vars() {
    m = 0;
    lmax = 131072; // This will create an array of size 131073 doubles ~ 1MB
    result_deriv_array = (double*)calloc(lmax - m + 1, sizeof(double));
}

void loop();