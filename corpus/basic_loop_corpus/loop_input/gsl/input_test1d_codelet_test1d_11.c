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
gsl_histogram *h1;
gsl_histogram *g;
size_t i;
int status;

static double *alloc_initialized_double_array(size_t size) {
    double *arr = (double *)calloc(size, sizeof(double));
    for (size_t idx = 0; idx < size; idx++) {
        arr[idx] = (double)(idx % 100) + 1.0;
    }
    return arr;
}

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h1 = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    g = (gsl_histogram *)malloc(sizeof(gsl_histogram));

    h->n = 400;
    h1->n = 400;
    g->n = 400;

    h->bin = alloc_initialized_double_array(h->n);
    h1->bin = alloc_initialized_double_array(h1->n);
    g->bin = alloc_initialized_double_array(g->n);

    h->range = NULL;
    h1->range = NULL;
    g->range = NULL;

    i = 0;
    status = 0;
}