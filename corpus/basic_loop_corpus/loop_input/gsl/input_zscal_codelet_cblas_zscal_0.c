#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N;
void *X;
int incX;
int i;
int ix;
double alpha_real;
double alpha_imag;

void init_vars() {
    // Estimate data size for ~0.01s runtime: assume moderate CPU speed and optimize for 16-64M elements
    // Each element is two doubles (real and imag), so 16 bytes per element
    // Aim for total memory access around 16 MB to 64 MB to hit ~0.01s on modern systems
    const size_t target_bytes = 32 * 1024 * 1024; // 32 MB target
    const size_t element_size = 2 * sizeof(double); // complex number: real + imag
    N = (int)(target_bytes / element_size);
    if (N <= 0) N = 1;

    // Allocate X as array of double, with space for 2 * N values (N complex numbers)
    X = aligned_alloc(32, 2 * N * sizeof(double));
    if (!X) {
        N = 0;
        return;
    }

    // Initialize X with random complex values
    double *dx = (double *)X;
    for (int j = 0; j < 2 * N; j++) {
        dx[j] = (double)rand() / RAND_MAX * 2.0 - 1.0; // Random in [-1, 1]
    }

    // Set stride: typically 1, but could be larger; use 1 for dense access
    incX = 1;

    // Initial index
    ix = 0;

    // Initialize alpha (complex scaling factor)
    alpha_real = 0.8;
    alpha_imag = 0.6;

    // Seed for reproducibility
    srand(12345);
}