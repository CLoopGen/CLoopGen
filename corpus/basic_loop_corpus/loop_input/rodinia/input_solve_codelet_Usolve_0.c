#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

u_int dim = 1 << 24; // 16M elements, roughly 128MB for two double arrays

int i;

double *b_ent;
double *out_ent;

void init_vars() {
    b_ent = (double *)aligned_alloc(32, dim * sizeof(double));
    out_ent = (double *)aligned_alloc(32, dim * sizeof(double));

    if (!b_ent || !out_ent) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (u_int j = 0; j < dim; j++) {
        b_ent[j] = (j % 7 == 0) ? 0.0 : 1.5;
        out_ent[j] = 0.0;
    }
}