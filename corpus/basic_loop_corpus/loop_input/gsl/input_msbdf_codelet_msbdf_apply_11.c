#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t dim;
double * z;
size_t ord;
size_t i;
size_t j;
size_t k;

void init_vars() {
    dim = 1024; 
    ord = 1000;

    z = (double *)calloc(dim * (ord + 1), sizeof(double));
    if (!z) {
        exit(1);
    }

    for (size_t idx = 0; idx < dim * (ord + 1); idx++) {
        z[idx] = 1.0;
    }
}