#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t dim;
double * z;
double * l;
size_t ord;
size_t i;
size_t j;

void init_vars() {
    dim = 4096;          
    ord = 512;           

    size_t z_size = (ord + 2) * dim;
    size_t l_size = ord + 1;

    z = (double*)calloc(z_size, sizeof(double));
    l = (double*)calloc(l_size, sizeof(double));

    if (!z || !l) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < z_size; idx++) {
        z[idx] = 1.0 + (idx % 100) * 0.01;
    }
    for (size_t idx = 0; idx < l_size; idx++) {
        l[idx] = 0.5 + (idx % 50) * 0.02;
    }
}