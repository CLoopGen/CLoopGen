#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *c1;
int k;
int q;

void init_vars() {
    q = 20000; // Choose size to make loop run ~0.01 seconds

    c1 = (VEC *)malloc(sizeof(VEC));
    c1->dim = q + 1;
    c1->max_dim = q + 1;
    c1->ve = (double *)aligned_alloc(32, (q + 1) * sizeof(double));

    for (int i = 0; i <= q; i++) {
        c1->ve[i] = 1.0;
    }
}