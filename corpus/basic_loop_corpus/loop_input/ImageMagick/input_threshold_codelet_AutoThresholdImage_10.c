#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double gamma;
double *histogram;
ssize_t i;

void init_vars() {
    gamma = 1.5;
    ssize_t size = 256;
    histogram = (double *)aligned_alloc(32, size * sizeof(double));
    for (ssize_t idx = 0; idx < size; idx++) {
        histogram[idx] = (double)(idx % 128);
    }
}