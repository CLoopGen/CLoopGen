#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *y;
double h;
size_t dim;
size_t i;
double *k1nu;
double *k2nu;

void init_vars() {
    // Set dimension to achieve approximately 0.01 seconds runtime
    // Assuming moderate CPU speed and cache effects, aim for ~64M elements for double (512 MB total)
    // Adjusted empirically to fit typical modern CPU performance
    dim = 64 * 1024 * 1024 / sizeof(double); // ~64M elements -> ~512MB accessed

    // Allocate arrays
    y = (double*)aligned_alloc(32, dim * sizeof(double));
    k1nu = (double*)aligned_alloc(32, dim * sizeof(double));
    k2nu = (double*)aligned_alloc(32, dim * sizeof(double));

    // Initialize all memory to avoid undefined behavior
    memset(y, 0, dim * sizeof(double));
    for (size_t idx = 0; idx < dim; idx++) {
        k1nu[idx] = 1.0 + idx * 0.001;
        k2nu[idx] = 2.0 - idx * 0.001;
    }

    // Initialize scalar values
    h = 0.25;

    // Ensure i is initialized properly in loop itself
}