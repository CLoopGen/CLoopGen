#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *x1;
VEC *x2;
VEC *out;
int i;

void init_vars() {
    size_t data_size = 1 << 24; // ~16 million elements, ~128 MB for three double arrays
    x1 = (VEC*)malloc(sizeof(VEC));
    x2 = (VEC*)malloc(sizeof(VEC));
    out = (VEC*)malloc(sizeof(VEC));

    x1->dim = data_size;
    x1->max_dim = data_size;
    x1->ve = (double*)malloc(data_size * sizeof(double));

    x2->dim = data_size;
    x2->max_dim = data_size;
    x2->ve = (double*)malloc(data_size * sizeof(double));

    out->dim = data_size;
    out->max_dim = data_size;
    out->ve = (double*)malloc(data_size * sizeof(double));

    for (size_t j = 0; j < data_size; j++) {
        x1->ve[j] = 1.0 + (j % 100) * 0.01;
        x2->ve[j] = 2.0 + (j % 75)  * 0.01;
        out->ve[j] = 0.0;
    }
    i = 0;
}