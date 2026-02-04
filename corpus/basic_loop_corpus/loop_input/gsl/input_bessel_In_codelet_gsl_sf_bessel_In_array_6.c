#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 13421772; // Size chosen so that (nmax - nmin + 1) * sizeof(double) ≈ 108 MB
double *result_array;
int j;

void init_vars() {
    ptrdiff_t size = (ptrdiff_t)(nmax - nmin + 1);
    result_array = (double*)calloc((size_t)size, sizeof(double));
    if (!result_array) {
        exit(1);
    }
}