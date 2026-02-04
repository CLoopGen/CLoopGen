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

void init_vars() {
    h = malloc(sizeof(gsl_histogram));
    h1 = malloc(sizeof(gsl_histogram));
    g = malloc(sizeof(gsl_histogram));

    h->n = 397;
    h1->n = 397;
    g->n = 397;

    h->bin = malloc(h->n * sizeof(double));
    h1->bin = malloc(h1->n * sizeof(double));
    g->bin = malloc(g->n * sizeof(double));

    for (size_t idx = 0; idx < 397; idx++) {
        h->bin[idx] = (double)(idx * 3);
        g->bin[idx] = (double)(idx * 5);
        h1->bin[idx] = g->bin[idx] - h->bin[idx];
    }

    i = 0;
    status = 0;
}