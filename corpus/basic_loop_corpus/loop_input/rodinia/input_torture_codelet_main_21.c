#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *u;
int i;

void init_vars() {
    u = (VEC *)malloc(sizeof(VEC));
    u->dim = 20000000;  // ~160 MB of double data (20M * 8 bytes)
    u->max_dim = u->dim;
    u->ve = (double *)malloc(u->dim * sizeof(double));

    for (u_int j = 0; j < u->dim; j++) {
        u->ve[j] = (double)(j % 2 ? -1 : 1) * (1.0 + (j % 1000)) / (j + 1);
    }
}