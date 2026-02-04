#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t dim = 1024;
double *z;
size_t ord = 1000;
size_t i;
size_t j;
double hrel = 1.001;
double coeff = 2.0;

void init_vars() {
    size_t total_size = (ord + 1) * dim;
    z = (double*)aligned_alloc(32, total_size * sizeof(double));
    if (!z) {
        exit(1);
    }
    for (size_t idx = 0; idx < total_size; ++idx) {
        z[idx] = 1.0 + (idx % 256);
    }
}