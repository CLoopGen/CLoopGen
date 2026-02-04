#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *histogram;
double *derivative;
ssize_t i;
ssize_t n;

void init_vars() {
    n = 64 * 1024 * 1024 / sizeof(double);  // ~512 MB of total data (two arrays)
    histogram = (double *)aligned_alloc(32, (n + 1) * sizeof(double));
    derivative = (double *)aligned_alloc(32, n * sizeof(double));

    for (ssize_t j = 0; j < n + 1; j++) {
        histogram[j] = (double)(j % 1000) / 10.0;
    }
    for (ssize_t j = 0; j < n; j++) {
        derivative[j] = 0.0;
    }

    i = 0;
}