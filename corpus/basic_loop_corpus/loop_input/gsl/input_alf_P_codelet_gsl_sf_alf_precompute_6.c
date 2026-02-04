#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

size_t lmax = 10000000; // ~160 MB of data (2 arrays of double, each 8 bytes per element)
double csfac = 1.5;
double *cl;
double *dl;
size_t l;

void init_vars() {
    cl = (double*)aligned_alloc(32, (lmax + 1) * sizeof(double));
    dl = (double*)aligned_alloc(32, (lmax + 1) * sizeof(double));

    if (!cl || !dl) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i <= lmax; ++i) {
        cl[i] = 0.0;
        dl[i] = 0.0;
    }
}