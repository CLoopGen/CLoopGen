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
uint16_t *pix;
int d;

static uint16_t *pix_buffer;

void init_vars() {
    // Set parameters to achieve roughly 0.01s runtime on modern CPU
    inner_iters = 10000;
    
    // Typical stride values for a 2D image-like access pattern
    xstride = 1;
    ystride = 16;
    
    // Filter thresholds
    alpha = 10;
    beta = 8;
    
    // Total number of iterations in loop: 4 * inner_iters
    // Maximum negative offset: -4 * xstride -> need at least 4 elements before current pix position
    // Maximum positive offset: 3 * xstride -> need up to 3 elements after q2 (which is at +2*xstride), so +3 total
    // So we need at least 4 (before) + 4*inner_iters*ystride + 3 (after) elements
    
    const int margin_before = 8;  // Extra safety margin
    const int margin_after = 8;
    const size_t total_elements = margin_before + (4 * inner_iters) * ystride + margin_after;
    
    // Allocate buffer with sufficient space
    pix_buffer = aligned_alloc(32, total_elements * sizeof(uint16_t));
    
    // Initialize with non-zero but valid pixel data (0-255 range for 16-bit storage)
    for (size_t i = 0; i < total_elements; i++) {
        pix_buffer[i] = (uint16_t)(i * 71 % 256); // Arbitrary deterministic pattern
    }
    
    // Set pix to point at the first usable position (after margin)
    pix = pix_buffer + margin_before;
}

// Cleanup function to avoid memory leaks (not called here but implied usage)
// Caller must ensure cleanup if needed