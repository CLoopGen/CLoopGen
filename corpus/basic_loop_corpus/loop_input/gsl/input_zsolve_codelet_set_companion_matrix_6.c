#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *a;
size_t nc;
double *m;
size_t i;

void init_vars() {
    nc = 10000; // Adjusted to ensure ~0.01s runtime

    a = (double*)aligned_alloc(32, nc * sizeof(double));
    m = (double*)aligned_alloc(32, nc * nc * sizeof(double));

    for (size_t idx = 0; idx < nc; ++idx) {
        a[idx] = 1.0 + idx * 0.1;
    }
    for (size_t idx = 0; idx < nc * nc; ++idx) {
        m[idx] = 0.0;
    }

    if (a[nc - 1] == 0.0) {
        a[nc - 1] = 1.0;
    }
}