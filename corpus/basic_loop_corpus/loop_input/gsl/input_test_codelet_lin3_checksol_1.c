#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *x;
size_t i;
double sum;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    x = (double*)aligned_alloc(32, data_size * sizeof(double));
    if (!x) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        x[idx] = (double)(idx % 1000) / 100.0;
    }
    i = 0;
    sum = 0.0;
}