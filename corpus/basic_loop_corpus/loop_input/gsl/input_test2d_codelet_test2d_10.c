#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

gsl_histogram2d *h;
gsl_histogram2d *h1;
size_t i;
int status;

void init_vars() {
    // Allocate memory for two histogram structures
    h = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    h1 = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));

    // Set dimensions: we need at least 108 elements in xrange (0..107)
    h->nx = 108;
    h1->nx = 108;
    h->ny = 1;
    h1->ny = 1;

    // Allocate large arrays to meet data size requirement (~1MB–256MB)
    // Each double is 8 bytes; 32 million doubles ~ 256MB
    const size_t total_size = 32000000;

    h->xrange = (double*)calloc(total_size, sizeof(double));
    h1->xrange = (double*)calloc(total_size, sizeof(double));
    h->yrange = (double*)calloc(total_size, sizeof(double));
    h1->yrange = (double*)calloc(total_size, sizeof(double));
    h->bin = (double*)calloc(total_size * 2, sizeof(double));  // Larger bin array
    h1->bin = (double*)calloc(total_size * 2, sizeof(double));

    // Initialize xrange arrays so that the loop condition fails only if needed
    // For correctness, make them equal in the first 108 elements
    for (size_t idx = 0; idx <= 107; idx++) {
        h->xrange[idx] = (double)idx * 1.5;
        h1->xrange[idx] = (double)idx * 1.5;
    }

    // Ensure rest of the data is initialized to avoid undefined behavior
    for (size_t idx = 108; idx < total_size; idx++) {
        h->xrange[idx] = (double)idx;
        h1->xrange[idx] = (double)idx;
        h->yrange[idx] = (double)(idx * 2);
        h1->yrange[idx] = (double)(idx * 2);
    }

    // Initialize bin arrays
    for (size_t idx = 0; idx < total_size * 2; idx++) {
        h->bin[idx] = 1.0;
        h1->bin[idx] = 1.0;
    }

    // Initialize status
    status = 0;
}