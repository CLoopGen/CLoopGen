#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N;
float *X;
int incX;
float *Y;
int incY;
double r;
int i;
int ix;
int iy;

void init_vars() {
    // Estimate data size for ~0.01s runtime: assume ~1e9 operations/sec, so ~1e7 iterations
    N = 10000000;

    // Ensure no out-of-bounds access: arrays must be large enough given incX, incY and starting indices
    size_t x_size = N * abs(incX) + 1;
    size_t y_size = N * abs(incY) + 1;

    // Choose reasonable stride values
    incX = 1;
    incY = 1;

    x_size = N * incX;
    y_size = N * incY;

    // Allocate arrays
    X = (float*)aligned_alloc(32, x_size * sizeof(float));
    Y = (float*)aligned_alloc(32, y_size * sizeof(float));

    // Initialize array elements to prevent undefined behavior
    for (size_t j = 0; j < x_size; j++) {
        X[j] = 1.0f + (j % 100) * 0.01f;
    }
    for (size_t j = 0; j < y_size; j++) {
        Y[j] = 2.0f + (j % 100) * 0.01f;
    }

    // Initialize loop indices
    ix = 0;
    iy = 0;

    // Initialize accumulator
    r = 0.0;

    // Seed and initialize other state if needed
    srand((unsigned int)time(NULL));
}