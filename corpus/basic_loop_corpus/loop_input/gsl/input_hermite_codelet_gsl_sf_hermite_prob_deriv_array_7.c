#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mmax;
int n;
double *result_array;
int j;

void init_vars() {
    mmax = 16777216; // ~128 MB of double data (16M elements)
    n = mmax - 1000;
    result_array = (double *)calloc(mmax + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
}