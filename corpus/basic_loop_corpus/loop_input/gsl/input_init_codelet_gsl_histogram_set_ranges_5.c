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
size_t n;

void init_vars() {
    n = 16777216; // ~128 MB of data (16M * sizeof(double) = 128MB), suitable for ~0.01 sec on modern CPU

    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    if (!h) exit(1);

    h->n = n;
    h->range = (double*)calloc(n + 1, sizeof(double));
    h->bin = (double*)calloc(n, sizeof(double));

    if (!h->range || !h->bin) exit(1);
}