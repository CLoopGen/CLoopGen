#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double smooth_threshold = 1e-5;
ssize_t i;
double *second_derivative;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 2^20 elements
    second_derivative = (double *)aligned_alloc(32, data_size * sizeof(double));
    if (!second_derivative) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        second_derivative[idx] = ((double)rand() / RAND_MAX) * 2e-5 - 1e-5;
    }

    smooth_threshold = 1e-5;
}