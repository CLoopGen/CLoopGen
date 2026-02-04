#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int N;
void *X;
int incX;
void *Y;
int incY;
int i;
int ix;
int iy;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume processing around 100 million doubles per second -> aim for ~1M to 10M elements
    size_t total_bytes = 64 * 1024 * 1024; // 64 MB total buffer size
    size_t num_doubles = total_bytes / sizeof(double);
    
    // Use half for X and half for Y to avoid overlap
    size_t num_elements = num_doubles / 4; // Each complex double has real and imag (2 doubles), so we have num_elements of complex numbers

    N = (int)num_elements;

    // Allocate aligned memory for X and Y
    X = aligned_alloc(32, 2 * N * sizeof(double));
    Y = aligned_alloc(32, 2 * N * sizeof(double));

    if (!X || !Y) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize X with some data
    double *dx = (double *)X;
    for (int j = 0; j < 2 * N; j++) {
        dx[j] = (double)(j % 12345) / 100.0;
    }

    // Clear Y
    memset(Y, 0, 2 * N * sizeof(double));

    // Set increments: typical stride of 1
    incX = 1;
    incY = 1;

    // Start from beginning
    ix = 0;
    iy = 0;
}