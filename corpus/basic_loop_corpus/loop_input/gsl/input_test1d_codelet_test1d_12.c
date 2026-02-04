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

static double *allocate_double_array(size_t size) {
    double *ptr = (double *)calloc(size, sizeof(double));
    return ptr;
}

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h1 = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    g = (gsl_histogram *)malloc(sizeof(gsl_histogram));

    h->n = 397;
    h1->n = 397;
    g->n = 397;

    h->bin = allocate_double_array(h->n);
    h1->bin = allocate_double_array(h1->n);
    g->bin = allocate_double_array(g->n);

    for (size_t idx = 0; idx < h->n; idx++) {
        h->bin[idx] = 1.0 + idx * 0.1;
        g->bin[idx] = 2.0 + idx * 0.2;
        h1->bin[idx] = g->bin[idx] / h->bin[idx];
    }

    i = 0;
    status = 0;
}