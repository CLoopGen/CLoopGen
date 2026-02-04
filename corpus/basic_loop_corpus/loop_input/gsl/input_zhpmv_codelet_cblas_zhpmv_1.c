#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 134217728; // 256MB / (2 * sizeof(double)) ≈ 134M complex numbers

void* Y;
int incY = 1;
int i;
double beta_real = 0.5;
double beta_imag = 0.866; // typical non-trivial rotation
int iy = 0;

void init_vars() {
    const size_t total_bytes = N * 2 * sizeof(double);
    Y = aligned_alloc(32, total_bytes);
    if (!Y) {
        exit(1);
    }
    double* y_ptr = (double*)Y;
    for (int idx = 0; idx < 2 * N; idx++) {
        y_ptr[idx] = (double)(idx % 127); // arbitrary initialization
    }
}