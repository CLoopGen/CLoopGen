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
    // Set image dimensions to achieve desired computation load
    width = 1024;
    height = 512;

    // Ensure each line size is at least width, possibly aligned
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate buffers with proper size including linesize padding
    size_t top_size = height * top_linesize;
    size_t bottom_size = height * bottom_linesize;
    size_t dst_size = height * dst_linesize;

    top_buffer = aligned_alloc(32, top_size * sizeof(uint16_t));
    bottom_buffer = aligned_alloc(32, bottom_size * sizeof(uint16_t));
    dst_buffer = aligned_alloc(32, dst_size * sizeof(uint16_t));

    if (!top_buffer || !bottom_buffer || !dst_buffer) {
        exit(1);
    }

    top = top_buffer;
    bottom = bottom_buffer;
    dst = dst_buffer;

    // Initialize top and bottom data with non-trivial values to exercise all code paths
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ptrdiff_t idx = y * top_linesize + x;
            top_buffer[idx] = (uint16_t)((x * 7 + y * 13) % 1024);
            bottom_buffer[idx] = (uint16_t)((x * 17 + y * 19) % 1024);
        }
    }

    // Clear destination
    memset(dst_buffer, 0, dst_size * sizeof(uint16_t));
}