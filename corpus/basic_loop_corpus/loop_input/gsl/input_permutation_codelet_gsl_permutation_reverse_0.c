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

void init_vars() {
    size = 134217728; // 128 million elements, roughly 1GB of size_t data (assuming 8 bytes per size_t)
    p = (gsl_permutation *)malloc(sizeof(gsl_permutation));
    if (!p) exit(1);
    p->size = size;
    p->data = (size_t *)malloc(size * sizeof(size_t));
    if (!p->data) exit(1);

    for (size_t idx = 0; idx < size; ++idx) {
        p->data[idx] = idx + 1;
    }
}