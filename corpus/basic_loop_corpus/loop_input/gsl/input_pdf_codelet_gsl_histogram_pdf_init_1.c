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
size_t n = 16777216; // ~134MB for two double arrays, tuned for ~0.01s runtime
double mean;

static double *alloc_and_init_double_array(size_t size) {
    double *arr = (double *)calloc(size, sizeof(double));
    for (size_t i = 0; i < size; i++) {
        arr[i] = (double)(i % 1000) + 1.0;
    }
    return arr;
}

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h->n = n;
    h->range = alloc_and_init_double_array(n + 1);
    h->bin = alloc_and_init_double_array(n);
    mean = 1.0;
    i = 0;
}