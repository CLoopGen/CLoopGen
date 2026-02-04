#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t dim;
double * z;
double * l;
size_t ord;
size_t i;
size_t j;

void init_vars() {
    dim = 4096;  
    ord = 1024;  

    size_t z_size = ord * dim * sizeof(double);
    size_t l_size = ord * sizeof(double);

    z = (double *)aligned_alloc(32, z_size);
    l = (double *)aligned_alloc(32, l_size);

    if (!z || !l) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < ord; ++idx) {
        l[idx] = 1.0 + idx * 0.001;
        for (size_t jdx = 0; jdx < dim; ++jdx) {
            z[idx * dim + jdx] = (double)(idx + jdx) * 0.0001;
        }
    }

    i = 0;
    j = 0;
}