#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

double xr[11] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};

gsl_histogram *hr;
size_t i;
int status;

void init_vars() {
    hr = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    if (!hr) {
        exit(1);
    }

    hr->n = 11;
    hr->range = (double*)malloc(11 * sizeof(double));
    hr->bin = (double*)malloc(11 * sizeof(double));
    if (!hr->range || !hr->bin) {
        exit(1);
    }

    for (size_t idx = 0; idx < 11; idx++) {
        hr->range[idx] = xr[idx];
    }

    i = 0;
    status = 0;
}