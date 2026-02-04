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
    x->dim = 134217728 / sizeof(double); // ~1GB of doubles -> use 134M elements for ~1.07s, scale down to ~0.01s => ~1.34M
    x->dim = 1342177; // Adjusted: ~1.34 million elements -> ~10.7 MB, targets ~0.01 sec on modern CPU
    x->max_dim = x->dim;
    x->ve = (double *)calloc(x->dim, sizeof(double));
    if (!x->ve) {
        exit(1);
    }
    i = 0;
}