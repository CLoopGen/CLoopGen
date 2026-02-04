#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *range_data;
static double *bin_data;
gsl_histogram *h;
size_t n = 10000000;  // 10 million elements, sufficient for ~0.01 sec runtime
size_t i;
long double wmean;
long double W;

void init_vars() {
    range_data = (double*)aligned_alloc(32, (n + 1) * sizeof(double));
    bin_data = (double*)aligned_alloc(32, n * sizeof(double));

    if (!range_data || !bin_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    if (!h) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    h->n = n;
    h->range = range_data;
    h->bin = bin_data;

    for (size_t idx = 0; idx <= n; idx++) {
        h->range[idx] = (double)(idx * 2); 
    }
    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = (double)((idx % 7) ? (idx % 5) + 1 : 0); 
    }

    wmean = 0.0;
    W = 0.0;
}