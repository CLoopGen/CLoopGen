#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *x;
int i;
int n;
double *Avlb;

void init_vars() {
    n = 16777216; // ~134MB of data (16M * sizeof(double) * 2), targets ~0.01 sec on modern CPUs

    x = (VEC *)malloc(sizeof(VEC));
    if (!x) exit(1);

    x->dim = n;
    x->max_dim = n;

    x->ve = (double *)aligned_alloc(32, n * sizeof(double));
    Avlb = (double *)aligned_alloc(32, n * sizeof(double));

    if (!x->ve || !Avlb) exit(1);

    for (int idx = 0; idx < n; idx++) {
        x->ve[idx] = (double)(idx + 1) * 1.5;
        Avlb[idx] = (double)(idx + 1) * 0.5 + 1.0; // avoid division by zero
    }
}