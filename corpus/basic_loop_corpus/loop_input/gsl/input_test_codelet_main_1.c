#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

int i;
double f[100];
int status;
gsl_histogram *h;

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h->n = 100;
    h->range = (double *)calloc(101, sizeof(double));
    h->bin = (double *)calloc(100, sizeof(double));

    for (int j = 0; j < 100; j++) {
        f[j] = (double)(j + 1) * 0.5;
        h->bin[j] = (double)(j + 1) * 0.5;
    }

    status = 0;
    i = 0;
}