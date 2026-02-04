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
float c;
float s;
int i;
int ix;
int iy;

void init_vars() {
    // Initialize scalar values
    N = 1 << 20; // 1 million elements, adjust for ~0.01 sec runtime
    incX = 1;
    incY = 1;
    c = 0.86602540378f; // cos(30°)
    s = 0.5f;          // sin(30°)
    i = 0;
    ix = 0;
    iy = 0;

    // Allocate arrays X and Y to avoid out-of-bounds access
    X = (float *)aligned_alloc(32, N * incX * sizeof(float));
    Y = (float *)aligned_alloc(32, N * incY * sizeof(float));

    // Initialize array contents
    for (int j = 0; j < N; j++) {
        X[j * incX] = (float)(drand48() * 2.0 - 1.0);
        Y[j * incY] = (float)(drand48() * 2.0 - 1.0);
    }
}