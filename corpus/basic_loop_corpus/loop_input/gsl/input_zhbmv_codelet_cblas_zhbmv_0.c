#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *Y;
int incY;
int i;
int iy;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // ~128 MB for sufficient runtime (~0.01 sec on modern CPU)
    const size_t num_elements = total_data_size / sizeof(double);
    
    // Ensure we have at least 2 elements per iteration (real and imaginary parts)
    N = num_elements / 2;

    Y = aligned_alloc(32, num_elements * sizeof(double));
    if (!Y) {
        fprintf(stderr, "Failed to allocate memory for Y\n");
        exit(1);
    }

    incY = 2; // Each step moves by 2 double elements (e.g., complex stride)
    iy = 0;   // Start from the beginning

    // Ensure that the loop does not exceed allocated bounds
    // Maximum index accessed: 2*(iy) + 1 at last iteration
    // At last iteration: iy_final = iy_initial + (N-1)*incY = 0 + (N-1)*2
    // Max index = 2*((N-1)*incY) + 1 = 2*((N-1)*2) + 1 = 4*N - 3
    // We require 4*N - 3 < num_elements => N <= (num_elements + 3)/4
    // So we clamp N accordingly
    N = (num_elements + 3) / 4;
}