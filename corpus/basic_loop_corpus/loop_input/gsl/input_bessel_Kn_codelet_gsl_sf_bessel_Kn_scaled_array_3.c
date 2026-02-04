#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 134217728; // ~134M elements to target ~0.01 sec runtime with 1GB/s memset-like speed
double *result_array;
int j;

void init_vars() {
    ptrdiff_t size = (nmax - nmin + 1);
    result_array = (double*)aligned_alloc(32, size * sizeof(double));
    if (!result_array) {
        exit(1);
    }
}