#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

u_int dim = 16777216; // ~16M elements, ~128MB for two double arrays, ensures ~0.01s runtime
u_int i = 0;
double *b_ve = NULL;
double *out_ve = NULL;

void init_vars() {
    b_ve = (double *)aligned_alloc(32, dim * sizeof(double));
    out_ve = (double *)aligned_alloc(32, dim * sizeof(double));

    if (!b_ve || !out_ve) {
        exit(1);
    }

    for (u_int idx = 0; idx < dim; idx++) {
        b_ve[idx] = 0.0;
        out_ve[idx] = 1.0;
    }

    b_ve[dim - 1] = 1.0;
}