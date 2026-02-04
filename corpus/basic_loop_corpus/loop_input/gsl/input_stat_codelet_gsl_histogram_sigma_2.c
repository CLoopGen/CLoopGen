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
size_t n = 1 << 20;  // Approximately 1 million elements for ~0.01 sec runtime
size_t i;
long double wvariance = 0.0L;
long double wmean = 123.456L;
long double W = 0.0L;

void init_vars() {
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    h->n = n;
    h->range = (double*)malloc((n + 1) * sizeof(double));
    h->bin = (double*)malloc(n * sizeof(double));

    for (size_t idx = 0; idx <= n; idx++) {
        h->range[idx] = (double)(idx * 2);
    }
    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = (double)((idx % 7) + 1);
    }
}