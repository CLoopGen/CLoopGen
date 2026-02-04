#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *alloc_initialized_double_array(size_t count) {
    double *arr = malloc(count * sizeof(double));
    for (size_t i = 0; i < count; ++i)
        arr[i] = (double)(i % 1000);
    return arr;
}

gsl_histogram *h;
gsl_histogram *hh;
size_t i;
int status;

void init_vars() {
    h = malloc(sizeof(gsl_histogram));
    hh = malloc(sizeof(gsl_histogram));

    h->n = 397;
    hh->n = 397;

    h->range = alloc_initialized_double_array(h->n);
    hh->range = alloc_initialized_double_array(hh->n);

    h->bin = alloc_initialized_double_array(h->n);
    hh->bin = alloc_initialized_double_array(hh->n);

    status = 0;
}