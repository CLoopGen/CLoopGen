#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *h;
size_t i;
int status;

static double *alloc_double_array(size_t size) {
    double *arr = malloc(size * sizeof(double));
    if (!arr) exit(1);
    return arr;
}

void init_vars() {
    h = malloc(sizeof(gsl_histogram));
    if (!h) exit(1);

    h->n = 397;
    h->range = alloc_double_array(h->n + 1);
    h->bin = alloc_double_array(h->n);

    for (size_t j = 0; j < h->n; j++) {
        h->bin[j] = (j % 13 == 0) ? 1.0 : 0.0;
    }

    for (size_t j = 0; j <= h->n; j++) {
        h->range[j] = j * 1.5;
    }

    i = 0;
    status = 0;
}