#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double range_data[12];  // Size to accommodate index up to 10 safely
static double bin_data[1];     // Minimal allocation for bin pointer

gsl_histogram *hr;
size_t i;

void init_vars() {
    hr = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    if (!hr) exit(1);

    hr->n = 12;
    hr->range = range_data;
    hr->bin = bin_data;
}