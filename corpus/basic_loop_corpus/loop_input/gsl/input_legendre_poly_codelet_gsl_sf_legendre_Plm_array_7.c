#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <time.h>
#include <math.h>

int lmax;
int m;
double x;
double *result_array;
double p_ellm2;
double p_ellm1;
double p_ell;
int ell;

void init_vars() {
    // Set parameters to ensure loop runs for a measurable duration (~0.01 sec)
    // The loop runs from m+2 to lmax, so we need enough iterations.
    // On a modern CPU, ~1e7 iterations should take about 0.01 seconds for this kind of computation.

    m = 2;
    lmax = 10000000;  // 10 million iterations: ell from m+2=4 to 10^7

    x = 0.75;

    // Initialize recurrence seeds
    p_ellm2 = 1.0;
    p_ellm1 = x;
    p_ell = 0.0;
    ell = 0;

    // Allocate result_array to hold values from index 0 to lmax - m
    size_t num_elements = lmax - m + 1;
    result_array = (double*)aligned_alloc(32, num_elements * sizeof(double));
    if (!result_array) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize array to zero (or some predictable value)
    for (size_t i = 0; i < num_elements; i++) {
        result_array[i] = 0.0;
    }
}