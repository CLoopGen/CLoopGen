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
    size_t data_size = 64 * 1024 * 1024; // ~512 MB of double data (64M doubles)
    size_t num_elements = data_size / sizeof(double);

    a = malloc(sizeof(VEC));
    b = malloc(sizeof(VEC));
    a2 = malloc(sizeof(VEC));
    b2 = malloc(sizeof(VEC));

    a->dim = num_elements;
    a->max_dim = num_elements;
    a->ve = malloc(num_elements * sizeof(double));

    b->dim = num_elements;
    b->max_dim = num_elements;
    b->ve = malloc(num_elements * sizeof(double));

    a2->dim = num_elements;
    a2->max_dim = num_elements;
    a2->ve = malloc(num_elements * sizeof(double));

    b2->dim = num_elements;
    b2->max_dim = num_elements;
    b2->ve = malloc(num_elements * sizeof(double));

    for (size_t j = 0; j < num_elements; j++) {
        a->ve[j] = (double)(j);
        b->ve[j] = (double)(j * 2);
    }

    i = 0;
}