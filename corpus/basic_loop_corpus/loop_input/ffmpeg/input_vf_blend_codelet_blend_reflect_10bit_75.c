#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity;
int i;
int j;

static uint16_t *top_buffer;
static uint16_t *bottom_buffer;
static uint16_t *dst_buffer;

void init_vars() {
    // Set dimensions to achieve ~100ms runtime
    // Each iteration does several integer and floating point ops; estimate 20-30 cycles per pixel
    // On a 3GHz CPU, 1M pixels ~ 10ms. Use ~4MP total pixels.
    width = 1280;
    height = 720;  // 1280x720 = 921,600 pixels

    // Account for cache effects and ensure non-unit strides
    top_linesize = width + 16;
    bottom_linesize = width + 32;
    dst_linesize = width + 48;

    opacity = 0.75;

    // Allocate buffers with padding to prevent overflow
    size_t top_size = height * top_linesize;
    size_t bottom_size = height * bottom_linesize;
    size_t dst_size = height * dst_linesize;

    top_buffer = aligned_alloc(32, top_size * sizeof(uint16_t));
    bottom_buffer = aligned_alloc(32, bottom_size * sizeof(uint16_t));
    dst_buffer = aligned_alloc(32, dst_size * sizeof(uint16_t));

    if (!top_buffer || !bottom_buffer || !dst_buffer) {
        exit(1);
    }

    memset(top_buffer, 0, top_size * sizeof(uint16_t));
    memset(bottom_buffer, 0, bottom_size * sizeof(uint16_t));
    memset(dst_buffer, 0, dst_size * sizeof(uint16_t));

    // Initialize valid data
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ptrdiff_t top_idx = y * top_linesize + x;
            ptrdiff_t bottom_idx = y * bottom_linesize + x;
            top_buffer[top_idx] = (uint16_t)((x * y + y) % 1024);
            bottom_buffer[bottom_idx] = (uint16_t)((x * x + y) % 1025);
            if (bottom_buffer[bottom_idx] > 1023) bottom_buffer[bottom_idx] = 1023;
        }
    }

    // Set initial pointers
    top = top_buffer;
    bottom = bottom_buffer;
    dst = dst_buffer;
}