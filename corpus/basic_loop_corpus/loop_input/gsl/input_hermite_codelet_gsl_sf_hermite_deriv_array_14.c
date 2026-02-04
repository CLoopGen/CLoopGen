#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mmax;
double *result_array;
int j;

void init_vars() {
    mmax = 16777216; // ~134MB for double array (16M * 8 bytes), targets ~0.01s runtime
    result_array = (double*)calloc(mmax + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
    j = 0;
}