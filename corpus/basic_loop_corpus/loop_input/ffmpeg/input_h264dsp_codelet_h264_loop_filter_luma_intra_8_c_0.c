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
    // Set parameters for reasonable execution time (~0.01 sec)
    // Based on typical modern CPU, aim for moderate data size
    const int total_pixels = 4 * 1024 * 1024; // ~4 million pixels
    inner_iters = 1024;
    
    xstride = 1;
    ystride = 1024; // stride larger than x to simulate 2D layout

    alpha = 10;
    beta = 9;

    // Allocate buffer with padding to prevent out-of-bounds access
    // Max negative offset: -4 * xstride -> need at least 4 before start
    // Max positive offset: 3 * xstride -> need at least 3 after end
    // We'll allocate a 2D buffer with safe margins
    const ptrdiff_t row_size = ystride;
    const int height = (4 * inner_iters) + 10; // account for loop iterations and safety
    const int width = row_size + 10;

    buffer = (uint8_t*)aligned_alloc(64, width * height);
    if (!buffer) exit(1);

    // Initialize buffer to non-zero to allow computation variation
    for (int i = 0; i < width * height; i++) {
        buffer[i] = (uint8_t)(i % 251);
    }

    // Set pix to point into the middle of padding so all offsets are valid
    pix = buffer + 4 * xstride + 5 * ystride; // ensure -4..+3 xstride is safe
}

// Cleanup function to avoid memory leaks (not called here but good practice)
// Caller must ensure cleanup if needed