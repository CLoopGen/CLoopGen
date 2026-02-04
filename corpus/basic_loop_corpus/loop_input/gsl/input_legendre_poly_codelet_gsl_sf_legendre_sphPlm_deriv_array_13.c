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
    lmax = 131072; 
    result_deriv_array = (double *)calloc(lmax - m + 1, sizeof(double));
}

void loop();