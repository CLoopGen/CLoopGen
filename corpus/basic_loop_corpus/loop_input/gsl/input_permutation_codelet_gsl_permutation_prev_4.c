#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};

typedef struct gsl_permutation_struct gsl_permutation;

gsl_permutation *p;
size_t size;
size_t i;
size_t j;
size_t k;

void init_vars() {
    size = 64000000; // ~64M elements to target ~0.01 sec runtime on modern CPU
    i = 1; // ensures j starts at i+2 = 3, so we need at least 4 elements; also keeps access within bounds
    k = 0; // initialized to valid index

    p = (gsl_permutation *)malloc(sizeof(gsl_permutation));
    if (!p) exit(1);

    p->size = size;
    p->data = (size_t *)malloc(size * sizeof(size_t));
    if (!p->data) exit(1);

    // Initialize data with pseudo-random values in a safe range
    for (size_t idx = 0; idx < size; idx++) {
        p->data[idx] = rand() % size;
    }

    // Ensure that i and k are within bounds and distinct
    if (i >= size) i = size / 2;
    if (k >= size) k = 0;
}