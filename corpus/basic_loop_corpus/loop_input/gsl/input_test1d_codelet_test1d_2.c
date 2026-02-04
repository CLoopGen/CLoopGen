#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *h;
gsl_histogram *g;
size_t i;

double *alloc_and_init_double_array(size_t size) {
    double *arr = (double *)calloc(size, sizeof(double));
    return arr;
}

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    g = (gsl_histogram *)malloc(sizeof(gsl_histogram));

    size_t data_size = 256 * 1024 * 1024 / (2 * sizeof(double)); // ~256MB for two arrays
    if (data_size < 397) data_size = 397;

    h->n = data_size;
    g->n = data_size;

    h->bin = alloc_and_init_double_array(data_size);
    g->bin = alloc_and_init_double_array(data_size);

    h->range = alloc_and_init_double_array(data_size + 1);
    g->range = alloc_and_init_double_array(data_size + 1);
}