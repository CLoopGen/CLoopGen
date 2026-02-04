#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *X;
int incX;
void *Y;
int incY;
double r_real;
double r_imag;
int i;
int ix;
int iy;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Assuming moderate CPU speed and cache effects, use ~16M complex pairs (~256MB total)
    N = 16777216;  // 2^24 elements -> 16M double pairs (each 16 bytes) = 256 MB

    // Allocate X and Y as arrays of complex numbers: each has real and imaginary parts (2 doubles)
    X = aligned_alloc(32, N * 2 * sizeof(double));
    Y = aligned_alloc(32, N * 2 * sizeof(double));

    // Initialize strides
    incX = 1;
    incY = 1;

    // Initialize starting indices
    ix = 0;
    iy = 0;

    // Initialize accumulators
    r_real = 0.0;
    r_imag = 0.0;

    // Initialize X and Y with simple non-zero values to avoid degenerate math
    double *x_data = (double *)X;
    double *y_data = (double *)Y;

    for (int j = 0; j < N; j++) {
        x_data[2*j]     = 1.0 + ((double)j / N);           // real part
        x_data[2*j + 1] = 0.5 - ((double)j / (2*N));       // imag part
        y_data[2*j]     = 0.8 - ((double)j / (1.5*N));     // real part
        y_data[2*j + 1] = 0.3 + ((double)j / (3*N));       // imag part
    }
}