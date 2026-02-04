#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double h_bin_data[397];
static double h1_bin_data[397];
static double g_bin_data[397];

gsl_histogram *h;
gsl_histogram *h1;
gsl_histogram *g;
size_t i;
int status;

void init_vars() {
    // Allocate histograms
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    h1 = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    g = (gsl_histogram*)malloc(sizeof(gsl_histogram));

    // Initialize histogram sizes
    h->n = 397;
    h1->n = 397;
    g->n = 397;

    // Assign pre-allocated arrays
    h->bin = h_bin_data;
    h1->bin = h1_bin_data;
    g->bin = g_bin_data;

    // Initialize bin data to ensure valid comparisons
    for (size_t idx = 0; idx < 397; idx++) {
        h->bin[idx] = 1.5 + idx * 0.1;
        g->bin[idx] = 2.5 - idx * 0.05;
        h1->bin[idx] = g->bin[idx] + h->bin[idx]; // Make condition false initially
    }

    // Perturb one element to trigger status = 1 if optimizer doesn't handle loop correctly
    h1->bin[396] += 0.01;

    // Initialize loop index and status
    i = 0;
    status = 0;
}