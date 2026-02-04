#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *d;
VEC *x;
VEC *out;
int i;

void init_vars() {
    size_t data_size = 1 << 24; // ~16M doubles, ~128 MB total for three arrays
    size_t bytes = data_size * sizeof(double);

    d = (VEC*)malloc(sizeof(VEC));
    x = (VEC*)malloc(sizeof(VEC));
    out = (VEC*)malloc(sizeof(VEC));

    d->dim = data_size;
    d->max_dim = data_size;
    d->ve = (double*)malloc(bytes);

    x->dim = data_size;
    x->max_dim = data_size;
    x->ve = (double*)malloc(bytes);

    out->dim = data_size;
    out->max_dim = data_size;
    out->ve = (double*)malloc(bytes);

    for (size_t i = 0; i < data_size; i++) {
        d->ve[i] = 1.0 + (i % 100) * 0.01;
        x->ve[i] = 2.0 + (i % 75) * 0.02;
        out->ve[i] = 0.0;
    }
}