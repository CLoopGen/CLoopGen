#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

VEC *x;
int i;
int i_max;
double max_val;
double tmp;

void init_vars() {
    const size_t data_size = 16777216; // ~134MB of doubles (16M elements)

    x = (VEC *)malloc(sizeof(VEC));
    if (!x) exit(1);

    x->dim = data_size;
    x->max_dim = data_size;

    x->ve = (double *)aligned_alloc(32, data_size * sizeof(double));
    if (!x->ve) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        x->ve[idx] = (double)(rand() % 1000000) / 10.0;
    }

    i = 0;
    i_max = 0;
    max_val = x->ve[0];
    tmp = 0.0;
}