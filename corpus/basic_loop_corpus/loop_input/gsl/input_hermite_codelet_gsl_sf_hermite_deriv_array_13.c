#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mmax;
double *result_array;
int j;

void init_vars() {
    mmax = 10000000;  // ~80 MB for double array, sufficient for ~0.01 sec on modern CPU
    result_array = (double*)calloc(mmax + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
}