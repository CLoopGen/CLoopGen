#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 13421772; // ~100 million iterations to target ~0.01 sec (assuming ~1 ns per iteration)
double *result_array;
int j;

void init_vars() {
    ptrdiff_t size = nmax - nmin + 1;
    result_array = (double*)calloc(size, sizeof(double));
    if (!result_array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}