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
size_t size = 1 << 20; // 1MB of size_t elements ~ 8MB data
size_t i = 100;
size_t j;
size_t k;

static size_t *alloc_and_init_data(size_t n) {
    size_t *data = (size_t *)calloc(n, sizeof(size_t));
    if (!data) exit(1);
    for (size_t idx = 0; idx < n; ++idx) {
        data[idx] = rand() % (n * 2); // random values
    }
    return data;
}

void init_vars() {
    p = (gsl_permutation *)malloc(sizeof(gsl_permutation));
    if (!p) exit(1);
    p->size = size;
    p->data = alloc_and_init_data(size);
    i = size / 4;
    k = i + 1;
    if (k >= size) k = size ? size - 1 : 0;
    j = 0;
}