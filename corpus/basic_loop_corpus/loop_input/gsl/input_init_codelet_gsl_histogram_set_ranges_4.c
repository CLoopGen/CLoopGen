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
double range[262144]; // ~2MB of data (262144 * sizeof(double) ≈ 2MB)
size_t i;
size_t n = 262143; // Ensures loop runs from 0 to n inclusive, fits in array

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    if (!h) exit(1);
    h->n = n;
    h->range = (double *)malloc((n + 1) * sizeof(double));
    if (!h->range) exit(1);
    h->bin = (double *)calloc(n, sizeof(double));
    if (!h->bin) exit(1);
}