#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

ptrdiff_t xstride;
ptrdiff_t ystride;
int inner_iters;
int alpha;
int beta;
uint8_t *pix;
int d;

static uint8_t *buffer;

void init_vars() {
    // Set parameters for reasonable execution time (~0.01s)
    // Based on typical modern CPU, aim for moderate data size: ~32-64MB
    const int width = 256;
    const int height = 1024;
    const int total_size = width * height;

    // Allocate a large enough buffer to allow safe access with negative and positive strides
    buffer = (uint8_t*)aligned_alloc(32, total_size * sizeof(uint8_t));
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pixel data with non-zero but valid values
    for (int i = 0; i < total_size; ++i) {
        buffer[i] = (uint8_t)(i % 251); // Prime number to avoid patterns
    }

    // Set xstride and ystride
    // Assume planar image layout: xstride is horizontal step, ystride is vertical
    xstride = 1;
    ystride = width;

    // Set loop control parameters
    inner_iters = 128;  // So d goes up to 4 * 128 = 512

    // Set filter thresholds
    alpha = 10;
    beta = 5;

    // Initialize pix to point at a safe starting location so that:
    // -3*xstride and 2*xstride offsets do not go out of bounds during the loop
    // We need at least 4 elements before and 3 after in the x direction
    // Start at row index >= 1 and <= height - 1, and column offset >= 4
    pix = buffer + (4 * xstride) + (1 * ystride);
}

// Cleanup function to avoid memory leaks (not required by problem, but good practice)
void cleanup() {
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
}