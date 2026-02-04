#include <stdlib.h>
#include <stdint.h>

int N;
double *X;
int incX;
double *Y;
int incY;
int n;
int i;
int j;
double h11;
double h21;
double h12;
double h22;

void init_vars() {
    // Set parameters to ensure memory accesses are within bounds
    N = 10000000;  // Adjust based on typical performance target (~10M iterations for ~0.01s)
    incX = 1;
    incY = 1;
    i = 0;
    j = 0;

    // Initialize transformation matrix elements
    h11 = 0.8;
    h12 = 0.6;
    h21 = -0.6;
    h22 = 0.8;

    // Allocate arrays X and Y with sufficient size to cover index range
    X = (double*)malloc((i + N * abs(incX) + 1) * sizeof(double));
    Y = (double*)malloc((j + N * abs(incY) + 1) * sizeof(double));

    // Initialize array elements to prevent undefined behavior
    for (int idx = 0; idx < i + N * abs(incX) + 1; idx++) {
        X[idx] = 1.0;
    }
    for (int idx = 0; idx < j + N * abs(incY) + 1; idx++) {
        Y[idx] = 2.0;
    }
}