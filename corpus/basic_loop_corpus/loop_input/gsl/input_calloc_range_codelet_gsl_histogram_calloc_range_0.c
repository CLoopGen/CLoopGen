#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

size_t n;
double *range;
size_t i;
gsl_histogram *h;

void init_vars() {
    n = 10000000; // ~80 MB for two double arrays, sufficient for ~0.01 sec runtime

    range = (double *)calloc(n + 1, sizeof(double));
    if (!range) {
        exit(1);
    }

    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    if (!h) {
        exit(1);
    }

    h->n = n;
    h->range = (double *)malloc((n + 1) * sizeof(double));
    if (!h->range) {
        exit(1);
    }
    h->bin = (double *)calloc(n, sizeof(double));
    if (!h->bin) {
        exit(1);
    }

    for (size_t idx = 0; idx <= n; idx++) {
        range[idx] = (double)(idx + 1);
    }
}