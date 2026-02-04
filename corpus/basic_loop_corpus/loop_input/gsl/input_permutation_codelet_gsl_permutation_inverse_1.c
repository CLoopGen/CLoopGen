#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};

typedef struct gsl_permutation_struct gsl_permutation;

gsl_permutation *inv;
gsl_permutation *p;
size_t size = 1 << 20; // Approximately 1 million elements
size_t i;

static size_t *alloc_initialized_size_t_array(size_t n) {
    size_t *arr = malloc(n * sizeof(size_t));
    for (size_t idx = 0; idx < n; idx++) {
        arr[idx] = idx;
    }
    return arr;
}

void init_vars() {
    p = malloc(sizeof(gsl_permutation));
    inv = malloc(sizeof(gsl_permutation));
    p->size = size;
    inv->size = size;
    p->data = alloc_initialized_size_t_array(size);
    inv->data = malloc(size * sizeof(size_t));

    for (size_t i = 0; i < size; i++) {
        size_t j = rand() % size;
        size_t temp = p->data[i];
        p->data[i] = p->data[j];
        p->data[j] = temp;
    }
}