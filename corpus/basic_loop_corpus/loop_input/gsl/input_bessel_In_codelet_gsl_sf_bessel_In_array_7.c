#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 131072; // Size chosen so that array has ~1MB of data (131072 * 8 bytes per double)
double *result_array;
int j;
double eax = 2.5;

void init_vars() {
    size_t size = (size_t)(nmax - nmin);
    result_array = (double*)aligned_alloc(32, size * sizeof(double));
    if (!result_array) {
        exit(1);
    }
    for (size_t i = 0; i < size; i++) {
        result_array[i] = 1.0 + i * 0.001;
    }
    eax = 1.75;
}