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
size_t i1 = 50;
size_t i2 = 100;
size_t i3 = 150;
size_t i4 = 200;
double expected;
int status = 0;

void init_vars() {
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    h->n = 397;
    h->range = (double*)calloc(h->n + 1, sizeof(double));
    h->bin = (double*)calloc(h->n, sizeof(double));

    for (size_t idx = 0; idx < h->n; idx++) {
        if (idx == i1) {
            h->bin[idx] = 1.0;
        } else if (idx == i2) {
            h->bin[idx] = 2.0;
        } else if (idx == i3) {
            h->bin[idx] = 3.0;
        } else if (idx == i4) {
            h->bin[idx] = 4.0;
        } else {
            h->bin[idx] = 0.0;
        }
    }
}