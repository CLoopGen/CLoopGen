#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_multiset_struct {
    size_t n;
    size_t k;
    size_t *data;
};

typedef struct gsl_multiset_struct gsl_multiset;

gsl_multiset *dest;
gsl_multiset *src;
size_t src_k;
size_t j;

void init_vars() {
    const size_t data_size = 16777216; // ~128 MB of data (16M * sizeof(size_t) == 128 MB on 64-bit)

    src_k = data_size;

    src = (gsl_multiset *)malloc(sizeof(gsl_multiset));
    dest = (gsl_multiset *)malloc(sizeof(gsl_multiset));

    if (!src || !dest) {
        exit(1);
    }

    src->n = data_size;
    src->k = data_size;
    src->data = (size_t *)malloc(data_size * sizeof(size_t));

    dest->n = data_size;
    dest->k = data_size;
    dest->data = (size_t *)malloc(data_size * sizeof(size_t));

    if (!src->data || !dest->data) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src->data[i] = i;
        dest->data[i] = 0;
    }
}