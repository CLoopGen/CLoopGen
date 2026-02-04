#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t xstride;
ptrdiff_t ystride;
int inner_iters;
int alpha;
int beta;
uint8_t *pix;
int d;

uint8_t *pix_buffer;

void init_vars() {
    // Set parameters
    inner_iters = 10000;  // Adjust to control total iterations: 4 * inner_iters
    xstride = 16;
    ystride = 1;
    alpha = 10;
    beta = 10;

    // Allocate sufficient buffer to prevent out-of-bounds access
    // We access: pix[-2*xstride], pix[-xstride], pix[0], pix[xstride]
    // So we need at least 2*xstride before start, and xstride after end
    const size_t padding_before = 2 * xstride;
    const size_t padding_after = xstride;
    const size_t useful_size = (4 * inner_iters) * ystride + 1; // worst-case linear advance

    const size_t total_size = padding_before + useful_size + padding_after;
    pix_buffer = (uint8_t*)aligned_alloc(32, total_size);
    if (!pix_buffer) {
        exit(1);
    }

    // Initialize buffer to reasonable values
    for (size_t i = 0; i < total_size; i++) {
        pix_buffer[i] = (uint8_t)(i % 251);
    }

    // Set pix to point at the start of useful data (after padding)
    pix = pix_buffer + padding_before;
}