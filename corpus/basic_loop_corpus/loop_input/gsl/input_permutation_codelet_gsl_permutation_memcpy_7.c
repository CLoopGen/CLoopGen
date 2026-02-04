#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};

typedef struct gsl_permutation_struct gsl_permutation;

gsl_permutation *dest;
gsl_permutation *src;
size_t src_size;
size_t j;

void init_vars() {
    src_size = 32 * 1024 * 1024; // ~256 MB of data (32M size_t elements, assuming 8 bytes each)

    src = (gsl_permutation *)malloc(sizeof(gsl_permutation));
    dest = (gsl_permutation *)malloc(sizeof(gsl_permutation));

    if (!src || !dest) {
        exit(1);
    }

    src->size = src_size;
    dest->size = src_size;

    src->data = (size_t *)malloc(src_size * sizeof(size_t));
    dest->data = (size_t *)malloc(src_size * sizeof(size_t));

    if (!src->data || !dest->data) {
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src->data[i] = i % 1024;
    }
}