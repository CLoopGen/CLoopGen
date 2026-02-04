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
    x->dim = 16777216; // ~134 MB of data (16,777,216 * sizeof(double))
    x->max_dim = x->dim;
    x->ve = (double *)malloc(x->dim * sizeof(double));
    
    for (u_int j = 0; j < x->dim; j++) {
        x->ve[j] = (double)rand() / RAND_MAX; // Random values in [0, 1)
    }
}