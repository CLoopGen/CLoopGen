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

void init_vars() {
    x = (VEC *)malloc(sizeof(VEC));
    if (!x) exit(1);

    x->dim = 134217728; // ~1073 MB of double data (134M elements), adjust for ~0.01s runtime
    x->max_dim = x->dim;
    x->ve = (double *)malloc(x->dim * sizeof(double));
    if (!x->ve) exit(1);
}