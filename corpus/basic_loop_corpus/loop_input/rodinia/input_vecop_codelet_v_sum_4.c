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
double sum;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // ~128 MB of doubles (each double is 8 bytes)
    x = (VEC*)malloc(sizeof(VEC));
    if (!x) exit(1);
    x->dim = data_size;
    x->max_dim = data_size;
    x->ve = (double*)malloc(data_size * sizeof(double));
    if (!x->ve) exit(1);

    for (size_t idx = 0; idx < data_size; idx++) {
        x->ve[idx] = 1.0; // Initialize to 1.0 for predictable summation
    }

    i = 0;
    sum = 0.0;
}