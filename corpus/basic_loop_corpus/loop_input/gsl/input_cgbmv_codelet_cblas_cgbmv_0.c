#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *Y;
int incY;
int i;
int lenY;
int iy;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // 64 MB of data
    const size_t num_floats = total_size / sizeof(float);
    
    // Ensure we have at least 2 * (iy + (lenY - 1) * incY) + 1 within bounds
    // We'll set lenY such that the loop writes to every incY-th pair
    lenY = num_floats / (2 * 1); // Conservative estimate when incY=1
    if (lenY == 0) lenY = 1;

    // Allocate Y as float array with sufficient size
    Y = aligned_alloc(32, total_size);
    
    // Set incY to a small stride, e.g., 1 logical step per iteration
    incY = 1;
    
    // Start iy at 0
    iy = 0;

    // Initialize all values in Y to avoid undefined behavior
    for (size_t idx = 0; idx < num_floats; idx++) {
        Y[idx] = 0.0f;
    }
}