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
double shift;
size_t i;

void init_vars() {
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    h->n = 16777216; // ~128 MB of data (16M * sizeof(double) * 2 arrays ≈ 128MB), adjust for ~0.01s runtime
    h->range = (double*)calloc(h->n + 1, sizeof(double));
    h->bin = (double*)calloc(h->n, sizeof(double));
    shift = 1.5;
    i = 0;
}