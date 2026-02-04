#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *Y;
int incY;
int i;
int lenY;
double beta_real;
double beta_imag;
int iy;

void init_vars() {
    const size_t element_size = 2 * sizeof(double); // Each complex number has real and imaginary parts
    const size_t total_bytes = 16 * 1024 * 1024; // Aim for ~16MB of data to target ~0.01s runtime
    lenY = total_bytes / element_size;

    // Allocate Y as array of double pairs (complex-like)
    Y = aligned_alloc(32, total_bytes);
    if (!Y) {
        fprintf(stderr, "Failed to allocate Y\n");
        exit(1);
    }

    // Initialize Y with non-zero values to ensure meaningful computation
    double *Yd = (double *)Y;
    for (int idx = 0; idx < 2 * lenY; idx++) {
        Yd[idx] = (double)(idx % 12345) * 0.01;
    }

    // Set parameters
    incY = 1;
    iy = 0;
    beta_real = 0.8;
    beta_imag = 0.6;
}