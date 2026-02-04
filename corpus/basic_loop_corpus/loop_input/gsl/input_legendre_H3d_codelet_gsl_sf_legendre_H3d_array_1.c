#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
double *result_array;
int ell;

void init_vars() {
    lmax = 131072; // Size chosen so that lmax+1 doubles ~ 1MB (131072 * 8 bytes)
    result_array = (double*)calloc(lmax + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
    ell = 0;
}