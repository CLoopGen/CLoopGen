#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *a;
VEC *b;
VEC *a2;
VEC *b2;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data to target ~0.01s runtime
    size_t vec_len = data_size / (4 * sizeof(double)); // Each of a, b, a2, b2 uses similar memory

    if (vec_len == 0) vec_len = 1000;

    a = (VEC*)malloc(sizeof(VEC));
    b = (VEC*)malloc(sizeof(VEC));
    a2 = (VEC*)malloc(sizeof(VEC));
    b2 = (VEC*)malloc(sizeof(VEC));

    a->dim = vec_len + 1;
    a->max_dim = vec_len + 1;
    a->ve = (double*)malloc((vec_len + 1) * sizeof(double));

    b->dim = vec_len + 1;
    b->max_dim = vec_len + 1;
    b->ve = (double*)malloc((vec_len + 1) * sizeof(double));

    a2->dim = vec_len;
    a2->max_dim = vec_len;
    a2->ve = (double*)malloc(vec_len * sizeof(double));

    b2->dim = vec_len;
    b2->max_dim = vec_len;
    b2->ve = (double*)malloc(vec_len * sizeof(double));

    for (size_t j = 0; j < vec_len + 1; j++) {
        a->ve[j] = (double)(j);
        b->ve[j] = (double)(j * 2);
    }

    for (size_t j = 0; j < vec_len; j++) {
        a2->ve[j] = 0.0;
        b2->ve[j] = 0.0;
    }

    i = 0;
}