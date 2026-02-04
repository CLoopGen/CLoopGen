#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *dest;
gsl_histogram *src;
size_t n = 131072;  // 131072 * sizeof(double) = 1MB per array
size_t i;

void init_vars() {
    // Allocate histogram structures
    dest = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    src = (gsl_histogram*)malloc(sizeof(gsl_histogram));

    // Set size
    dest->n = n;
    src->n = n;

    // Allocate arrays
    dest->range = (double*)malloc(n * sizeof(double));
    dest->bin   = (double*)malloc(n * sizeof(double));
    src->range = (double*)malloc(n * sizeof(double));
    src->bin   = (double*)malloc(n * sizeof(double));

    // Initialize src.bin with some data
    for (size_t idx = 0; idx < n; idx++) {
        src->bin[idx] = (double)(idx % 1000);
    }

    // Ensure no out-of-bounds access: loop uses i from 0 to n-1, so set n correctly
    // Already set above.
}