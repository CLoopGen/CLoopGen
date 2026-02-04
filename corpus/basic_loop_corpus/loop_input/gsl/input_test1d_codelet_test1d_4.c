#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

double xr[11];
gsl_histogram *hr;
size_t i;
int status;

void init_vars() {
    // Allocate and initialize hr
    hr = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    if (!hr) {
        status = 1;
        return;
    }

    // Allocate range array with 11 elements to match loop bounds (0 to 10)
    hr->n = 11;
    hr->range = (double *)malloc(hr->n * sizeof(double));
    hr->bin = NULL;  // Not used in loop, can be NULL

    if (!hr->range) {
        status = 1;
        return;
    }

    // Initialize xr and hr->range
    // Make them equal so the condition (hr->range[i] != xr[i]) is false for all i
    // Thus status remains 0 unless something goes wrong
    for (size_t idx = 0; idx <= 10; idx++) {
        xr[idx] = (double)(idx + 1) * 1.5;
        hr->range[idx] = xr[idx];
    }

    // Initialize status to 0 (success)
    status = 0;
}