#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *h1;
gsl_histogram *g;
size_t i;
int status;

void init_vars() {
    h1 = malloc(sizeof(gsl_histogram));
    g = malloc(sizeof(gsl_histogram));

    h1->n = 397;
    g->n = 397;

    h1->bin = malloc(h1->n * sizeof(double));
    g->bin = malloc(g->n * sizeof(double));

    for (size_t idx = 0; idx < 397; idx++) {
        h1->bin[idx] = 1.0 + idx * 0.001;
        g->bin[idx] = 2.0 + idx * 0.001;
    }

    i = 0;
    status = 0;
}