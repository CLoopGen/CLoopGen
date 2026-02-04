#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 131072; // Adjusted for ~0.01s runtime (each iteration processes 16 bytes, total ~2MB)

void *Y;
int incY;
int i;
double beta_real = 0.866025; // Example value, e.g., cos(π/6)
double beta_imag = 0.5;      // Example value, e.g., sin(π/6)
int iy = 0;

void init_vars() {
    // Allocate Y as an array of double complex values, 2 doubles per element
    Y = aligned_alloc(32, N * 2 * sizeof(double));
    if (!Y) {
        exit(1);
    }

    // Initialize Y with sample data to avoid NaNs or extreme values
    double *dy = (double *)Y;
    for (int idx = 0; idx < 2 * N; idx++) {
        dy[idx] = (double)(idx % 128) / 4.0;
    }

    // Set increment for stride access (commonly 1, but can be larger)
    incY = 1;
}

// Do not include main or extra functions beyond init_vars and global definitions