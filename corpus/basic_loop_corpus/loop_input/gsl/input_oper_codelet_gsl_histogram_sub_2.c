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

    h1->n = 10000000; // ~80 MB of data (10M * 8 bytes per double)
    h2->n = h1->n;

    h1->bin = (double *)aligned_alloc(32, h1->n * sizeof(double));
    h2->bin = (double *)aligned_alloc(32, h2->n * sizeof(double));
    h1->range = NULL;
    h2->range = NULL;

    for (size_t j = 0; j < h1->n; j++) {
        h1->bin[j] = (double)(j % 1000) + 1.5;
        h2->bin[j] = (double)(j % 500) + 0.5;
    }
}