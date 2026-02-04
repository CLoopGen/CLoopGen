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
double min;

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h->n = 10000000;  // ~80 MB for bin array, sufficient for ~0.01 sec runtime
    h->range = (double *)calloc(h->n + 1, sizeof(double));
    h->bin = (double *)malloc(h->n * sizeof(double));

    for (size_t idx = 0; idx < h->n; idx++) {
        h->bin[idx] = (double)(h->n - idx) * 0.5;  // decreasing sequence to trigger min updates
    }

    min = h->bin[0];  // initialize min to first element
}