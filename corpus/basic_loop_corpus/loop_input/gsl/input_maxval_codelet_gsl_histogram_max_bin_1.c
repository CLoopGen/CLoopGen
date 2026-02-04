#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static gsl_histogram h_storage;
gsl_histogram *h = &h_storage;
size_t i;
size_t imax;
double max;

void init_vars() {
    h->n = 16777216; // ~134 MB for two double arrays (n and range), tuned for ~0.01 sec runtime

    h->range = (double*)calloc(h->n + 1, sizeof(double));
    h->bin   = (double*)calloc(h->n,     sizeof(double));

    if (!h->range || !h->bin) {
        exit(1);
    }

    // Initialize range as monotonically increasing
    for (size_t j = 0; j <= h->n; j++) {
        h->range[j] = (double)j * 1.5;
    }

    // Initialize bin with randomish values to simulate histogram counts
    for (size_t j = 0; j < h->n; j++) {
        h->bin[j] = (double)(rand() % 10000) / 100.0;
    }

    // Ensure at least one element triggers the update
    h->bin[0] = -1.0;
    max = -2.0;
    imax = 0;
}