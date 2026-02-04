#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t N = 131072;
size_t tda = 1;
size_t i;

double *data;

void init_vars() {
    data = (double*)aligned_alloc(32, N * tda * sizeof(double));
    if (!data) {
        exit(EXIT_FAILURE);
    }
}