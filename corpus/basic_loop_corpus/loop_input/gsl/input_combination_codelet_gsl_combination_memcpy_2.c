#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_combination_struct {
    size_t n;
    size_t k;
    size_t *data;
};

typedef struct gsl_combination_struct gsl_combination;

gsl_combination *dest;
gsl_combination *src;
size_t src_k;
size_t j;

void init_vars() {
    const size_t data_size = 16777216; // ~128 MB of data (16M * sizeof(size_t) on 64-bit)

    src_k = data_size;

    src = (gsl_combination *)calloc(1, sizeof(gsl_combination));
    dest = (gsl_combination *)calloc(1, sizeof(gsl_combination));

    if (!src || !dest) {
        exit(EXIT_FAILURE);
    }

    src->n = data_size;
    src->k = data_size;
    src->data = (size_t *)calloc(data_size, sizeof(size_t));

    dest->n = data_size;
    dest->k = data_size;
    dest->data = (size_t *)calloc(data_size, sizeof(size_t));

    if (!src->data || !dest->data) {
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < data_size; i++) {
        src->data[i] = i;
    }
}