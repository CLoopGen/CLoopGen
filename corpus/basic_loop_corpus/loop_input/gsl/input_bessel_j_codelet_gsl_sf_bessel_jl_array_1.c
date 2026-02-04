#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
double *result_array;
int j;

void init_vars() {
    size_t data_size = 1 << 24;  // ~16.7 million elements, ~128MB for double
    result_array = (double *)calloc(data_size, sizeof(double));
    if (!result_array) {
        exit(1);
    }
    lmax = (int)(data_size - 1);
}