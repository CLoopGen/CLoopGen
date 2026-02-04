#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *dest;
gsl_histogram *src;
size_t n;
size_t i;

void init_vars() {
    n = 16777216; // ~128 MB of data (16M * sizeof(double) * 2 arrays)

    src = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    dest = (gsl_histogram*)malloc(sizeof(gsl_histogram));

    src->n = n;
    dest->n = n;

    src->range = (double*)malloc((n + 1) * sizeof(double));
    dest->range = (double*)malloc((n + 1) * sizeof(double));

    src->bin = (double*)malloc(n * sizeof(double));
    dest->bin = (double*)malloc(n * sizeof(double));

    for (size_t idx = 0; idx <= n; idx++) {
        src->range[idx] = (double)(idx & 0xFF);
    }

    for (size_t idx = 0; idx < n; idx++) {
        src->bin[idx] = (double)(idx % 1000);
    }
}