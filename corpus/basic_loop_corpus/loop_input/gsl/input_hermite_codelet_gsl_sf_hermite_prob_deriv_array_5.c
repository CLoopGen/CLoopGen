#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mmax;
double *result_array;
int j;

void init_vars() {
    mmax = 10000000;  // Approximately 80 MB for double array (10M * 8 bytes)
    result_array = (double *)calloc(mmax + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
}