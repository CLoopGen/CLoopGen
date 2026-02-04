#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *h1;
gsl_histogram *h2;
size_t i;

void init_vars() {
    h1 = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h2 = (gsl_histogram *)malloc(sizeof(gsl_histogram));

    h1->n = 16777216; // ~134 MB of data (16M * sizeof(double) * 2 histograms ≈ 268 MB)
    h2->n = h1->n;

    h1->range = (double *)calloc(h1->n + 1, sizeof(double));
    h1->bin   = (double *)calloc(h1->n,     sizeof(double));
    h2->range = (double *)calloc(h2->n + 1, sizeof(double));
    h2->bin   = (double *)calloc(h2->n,     sizeof(double));

    for (size_t j = 0; j < h1->n; j++) {
        h1->bin[j] = 1.0;
        h2->bin[j] = 2.0;
    }
}