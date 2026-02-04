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
size_t n = 10000000;  // 10 million elements for ~0.01 sec runtime
size_t i;
double max;

void init_vars() {
    // Allocate histogram structure
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    
    // Set n to the desired size
    h->n = n;
    
    // Allocate bin array with n doubles
    h->bin = (double *)malloc(n * sizeof(double));
    
    // Allocate range array (n+1 doubles as typical for histograms)
    h->range = (double *)malloc((n + 1) * sizeof(double));
    
    // Initialize bin values to random positive values below a threshold
    for (size_t idx = 0; idx < n; idx++) {
        h->bin[idx] = (double)(rand() % 1000) / 10.0;  // 0.0 to 99.9
    }
    
    // Initialize max to a value lower than expected maximum
    max = -1.0;
    
    // Optionally initialize range array meaningfully
    h->range[0] = 0.0;
    for (size_t idx = 1; idx <= n; idx++) {
        h->range[idx] = h->range[idx-1] + 1.0;
    }
}