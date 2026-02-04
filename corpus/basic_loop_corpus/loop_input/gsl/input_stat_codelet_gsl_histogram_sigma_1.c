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
size_t n = 1 << 20;  // 1 million elements, adjust for ~0.01 sec runtime
size_t i;
long double wmean;
long double W;

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h->n = n;
    h->range = (double *)aligned_alloc(32, (n + 1) * sizeof(double));
    h->bin = (double *)aligned_alloc(32, n * sizeof(double));

    for (size_t idx = 0; idx <= n; idx++) {
        h->range[idx] = (double)(idx * 2);  // Ensure valid range values
    }
    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = (double)((idx % 7) + 1);  // Positive weights to trigger conditional
    }

    i = 0;
    wmean = 0.0;
    W = 0.0;
}