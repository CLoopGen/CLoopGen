#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *src;
size_t n = 1000000;  // ~8MB of data (1e6 * sizeof(double) ≈ 8MB), suitable for ~0.01s runtime
size_t i;
gsl_histogram *h;

void init_vars() {
    // Allocate histograms
    src = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));

    // Set consistent size
    src->n = n;
    h->n = n;

    // Allocate arrays
    src->bin = (double*)malloc(n * sizeof(double));
    h->bin = (double*)malloc(n * sizeof(double));

    // Initialize src->bin with dummy data
    for (size_t idx = 0; idx < n; idx++) {
        src->bin[idx] = (double)(idx % 1000);
    }

    // Zero out h->bin initially
    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = 0.0;
    }
}