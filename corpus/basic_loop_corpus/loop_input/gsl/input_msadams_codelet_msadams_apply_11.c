#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t dim;
double *z;
size_t ord;
size_t i;
size_t j;
size_t k;

void init_vars() {
    dim = 1024; 
    ord = 512;

    z = (double*)aligned_alloc(64, (ord + 1) * dim * sizeof(double));
    if (!z) {
        exit(1);
    }

    for (size_t idx = 0; idx < (ord + 1) * dim; idx++) {
        z[idx] = 1.0;
    }
}