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

uint16_t *pix_buffer;

void init_vars() {
    // Set parameters for reasonable execution time (~0.01 seconds)
    // Based on typical loop filter usage in video decoding, assume moderate block count
    inner_iters = 10000;  // Controls outer loop: total iterations = 4 * inner_iters

    // Typical stride values for chroma processing (e.g., 8x8 or 16x16 blocks)
    xstride = 8;
    ystride = 8;

    alpha = 10;
    beta = 5;

    // Allocate buffer with margin to prevent out-of-bounds access
    // Accesses: pix[-2*xstride], pix[-1*xstride], pix[0], pix[1*xstride]
    // So we need at least 2*xstride before and 1*xstride after useful data
    const int margin_before = 2 * xstride;
    const int margin_after = 1 * xstride;
    const int total_size = (4 * inner_iters) * ystride + margin_before + margin_after;

    pix_buffer = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    if (!pix_buffer) {
        exit(1);
    }

    // Set pix to point at the first valid position after margin
    pix = pix_buffer + margin_before;

    // Initialize pixel data to plausible values to ensure defined behavior
    for (int i = 0; i < 4 * inner_iters; i++) {
        const int idx = i * ystride;
        pix[idx - 2*xstride] = 128 + ((i + 0) % 32);
        pix[idx - 1*xstride] = 128 + ((i + 1) % 32);
        pix[idx]           = 128 + ((i + 2) % 32);
        pix[idx + 1*xstride] = 128 + ((i + 3) % 32);
    }
}