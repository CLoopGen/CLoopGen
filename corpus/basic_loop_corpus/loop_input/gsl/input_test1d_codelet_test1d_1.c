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
size_t i;

void init_vars() {
    h1 = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h1->n = 398;
    h1->range = (double *)malloc(h1->n * sizeof(double));
    h1->bin = (double *)malloc((h1->n - 1) * sizeof(double));
}