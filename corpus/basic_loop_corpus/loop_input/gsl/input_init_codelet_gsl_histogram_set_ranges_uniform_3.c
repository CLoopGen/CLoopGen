#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *bin_array;
static gsl_histogram h_instance;
gsl_histogram *h = &h_instance;
size_t i;
size_t n;

void init_vars() {
    n = 16777216; // ~128 MB for bin array (16M * 8 bytes per double)

    bin_array = (double *)calloc(n, sizeof(double));
    if (!bin_array) {
        exit(1);
    }

    h->n = n;
    h->range = NULL;
    h->bin = bin_array;
}

// DO NOT include main(), headers, explanations or comments beyond this point