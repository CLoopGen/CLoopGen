#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *range_h;
static double *range_h1;
gsl_histogram *h;
gsl_histogram *h1;
size_t i;
int status;

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h1 = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    
    h->n = 398;
    h1->n = 398;

    range_h = (double *)malloc(h->n * sizeof(double));
    range_h1 = (double *)malloc(h1->n * sizeof(double));

    for (size_t idx = 0; idx < h->n; idx++) {
        range_h[idx] = (double)(idx * 2);
        range_h1[idx] = (double)(idx * 2 + 1);
    }

    h->range = range_h;
    h1->range = range_h1;

    i = 0;
    status = 0;
}