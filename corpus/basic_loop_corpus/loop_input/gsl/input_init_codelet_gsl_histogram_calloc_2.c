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
gsl_histogram *h;
size_t i;

void init_vars() {
    n = 16777216; // ~16.7M elements, aiming for ~0.01 sec runtime

    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    if (!h) exit(1);

    h->n = n;

    h->range = (double *)calloc(n + 1, sizeof(double));
    if (!h->range) exit(1);

    h->bin = (double *)malloc(n * sizeof(double));
    if (!h->bin) exit(1);
}