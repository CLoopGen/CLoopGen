#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint8_t *top;
ptrdiff_t top_linesize;
uint8_t *bottom;
ptrdiff_t bottom_linesize;
uint8_t *dst;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
double opacity;
int i;
int j;

static uint8_t *top_data;
static uint8_t *bottom_data;
static uint8_t *dst_data;

void init_vars() {
    // Set dimensions to achieve ~100ms runtime
    // Each inner loop iteration: 1 load top, 1 load bottom, 1 arithmetic, 1 store
    // Estimate: ~4 operations per byte, modern CPU does ~1e9 ops/sec -> ~250M bytes/sec
    // For 0.01s: aim for ~2.5M processed bytes
    width = 2048;
    height = 1024;  // Total ~2M pixels = ~2MB data

    // Allocate image data with proper alignment
    top_data = aligned_alloc(32, width * height * sizeof(uint8_t));
    bottom_data = aligned_alloc(32, width * height * sizeof(uint8_t));
    dst_data = aligned_alloc(32, width * height * sizeof(uint8_t));

    // Initialize with non-zero pattern to make debugging easier
    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (uint8_t)(idx & 0xFF);
        bottom_data[idx] = (uint8_t)((idx * 7) & 0xFF);
        dst_data[idx] = 0;
    }

    // Set line strides (allowing for potential padding; here we use tight packing)
    top_linesize = width * sizeof(uint8_t);
    bottom_linesize = width * sizeof(uint8_t);
    dst_linesize = width * sizeof(uint8_t);

    // Set initial pointers to start of images
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    // Set opacity to a fractional value to exercise floating-point math
    opacity = 0.75;

    // Ensure no out-of-bounds access in loop:
    // - Loop runs from i=0 to height-1, j=0 to width-1
    // - Pointers are updated by linesize after each row
    // - Our allocation covers exactly height rows of width bytes
}