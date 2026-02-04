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
size_t i;
size_t count;
size_t min;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements for ~0.01 sec runtime

    p = (gsl_permutation*)malloc(sizeof(gsl_permutation));
    if (!p) exit(1);

    p->size = data_size;
    p->data = (size_t*)malloc(data_size * sizeof(size_t));
    if (!p->data) exit(1);

    // Initialize data with descending values to ensure some updates to 'min'
    for (size_t idx = 0; idx < data_size; idx++) {
        p->data[idx] = data_size - idx;
    }

    i = 0;
    count = 0;
    min = data_size; // larger than any element, so first element will update it
}