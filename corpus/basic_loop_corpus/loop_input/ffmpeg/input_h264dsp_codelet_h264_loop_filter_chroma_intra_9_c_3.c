#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t xstride;
ptrdiff_t ystride;
int inner_iters;
int alpha;
int beta;
uint16_t *pix;
int d;

uint16_t *pix_data;

void init_vars() {
    // Set parameters to control loop iterations and memory layout
    inner_iters = 10000;  // controls 4 * inner_iters loop iterations
    xstride = 8;
    ystride = 16;
    alpha = 10;
    beta = 10;

    // Total required size: ensure we can access [-2*xstride] to [xstride] safely
    // Maximum negative offset: -2 * xstride = -16
    // Maximum positive offset: 1 * xstride = 8
    // So we need at least 16 + (ystride * (4 * inner_iters - 1)) + 8 elements
    ptrdiff_t total_elements = 16 + (ystride * (4 * inner_iters - 1)) + 8;
    pix_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    if (!pix_data) {
        exit(1);
    }

    // Initialize pixel data to reasonable values for filtering
    for (ptrdiff_t i = 0; i < total_elements; i++) {
        pix_data[i] = (i % 256) + 100;
    }

    // Set initial pix pointer to base + left padding (to allow -2*xstride offset)
    pix = pix_data + 16;
}