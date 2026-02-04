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
size_t count;
size_t i;
size_t j;
size_t size;

void init_vars() {
    size = 16384; // Adjusted to achieve ~0.01s runtime
    p = (gsl_permutation *)malloc(sizeof(gsl_permutation));
    p->size = size;
    p->data = (size_t *)malloc(size * sizeof(size_t));

    for (size_t idx = 0; idx < size; idx++) {
        p->data[idx] = rand() % (size * 2); // Random values to ensure comparisons occur
    }

    count = 0;
    i = 0;
    j = 0;
}