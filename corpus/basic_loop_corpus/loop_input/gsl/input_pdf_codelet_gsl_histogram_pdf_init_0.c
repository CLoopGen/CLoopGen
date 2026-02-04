#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *sum;
} gsl_histogram_pdf;

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram_pdf *p;
gsl_histogram *h;
size_t i;
size_t n;

void init_vars() {
    n = 13421772;  // ~2^23 elements, leads to ~100ms on modern CPUs for this memory-bound loop

    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    p = (gsl_histogram_pdf*)malloc(sizeof(gsl_histogram_pdf));

    h->n = n + 1;
    p->n = n + 1;

    h->range = (double*)malloc((n + 1) * sizeof(double));
    p->range = (double*)malloc((n + 1) * sizeof(double));
    p->sum = (double*)malloc((n + 1) * sizeof(double));
    h->bin = (double*)malloc(n * sizeof(double));

    for (size_t idx = 0; idx < n + 1; idx++) {
        h->range[idx] = (double)(idx % 1000) + 0.5;
    }

    for (size_t idx = 0; idx < n + 1; idx++) {
        p->range[idx] = 0.0;
    }

    for (size_t idx = 0; idx < n + 1; idx++) {
        p->sum[idx] = 0.0;
    }

    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = (double)(idx % 500) + 0.25;
    }
}