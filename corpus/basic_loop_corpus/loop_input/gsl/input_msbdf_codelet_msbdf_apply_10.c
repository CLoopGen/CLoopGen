#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t dim = 1024;
double *z = NULL;
size_t ord = 128;
size_t i = 0;
size_t j = 0;
double hrel = 1.05;
double coeff = 2.0;

void init_vars() {
    size_t total_size = (ord + 1) * dim;
    z = (double*)calloc(total_size, sizeof(double));
    if (!z) {
        exit(1);
    }
    for (size_t idx = 0; idx < total_size; idx++) {
        z[idx] = 1.0;
    }
}