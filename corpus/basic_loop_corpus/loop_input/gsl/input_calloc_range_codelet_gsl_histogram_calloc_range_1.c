#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

size_t n = 134217728; // 128 million elements, ~1GB for double array
size_t i;
gsl_histogram *h;

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    if (!h) exit(1);

    h->n = n;

    h->range = (double *)calloc(n + 1, sizeof(double));
    if (!h->range) exit(1);

    h->bin = (double *)calloc(n, sizeof(double));
    if (!h->bin) exit(1);
}