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
int status;

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h->n = 397;
    h->bin = (double *)malloc(h->n * sizeof(double));

    for (size_t idx = 0; idx < h->n; idx++) {
        h->bin[idx] = (double)idx;
    }

    i = 0;
    status = 0;
}