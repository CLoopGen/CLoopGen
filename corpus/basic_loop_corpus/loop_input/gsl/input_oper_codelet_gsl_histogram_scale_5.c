#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *generated_bin;
static double *generated_range;
gsl_histogram *h;
double scale;
size_t i;

void init_vars() {
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    if (!h) exit(1);

    // Aim for ~64 million elements to target ~0.01 sec runtime on modern CPUs
    h->n = 8000000;  // Approximately 64 MB of data (8e6 * 8 bytes per double)

    generated_bin = (double *)calloc(h->n, sizeof(double));
    generated_range = (double *)calloc(h->n + 1, sizeof(double));  // range has n+1 elements typically

    if (!generated_bin || !generated_range) exit(1);

    for (size_t idx = 0; idx < h->n; idx++) {
        generated_bin[idx] = 1.0 + (idx * 0.001);  // non-zero to allow scaling effect
        generated_range[idx] = idx * 1.0;
    }
    generated_range[h->n] = h->n * 1.0;

    h->bin = generated_bin;
    h->range = generated_range;

    scale = 2.5;
    i = 0;
}