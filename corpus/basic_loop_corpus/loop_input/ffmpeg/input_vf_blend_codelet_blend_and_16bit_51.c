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

void init_vars() {
    // Set image dimensions
    width = 2048;
    height = 128;

    // Ensure each line size is in units of uint16_t elements
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    // Allocate memory for arrays: total size ~ height * width * sizeof(uint16_t)
    // This gives about 2048 * 128 * 2 = 524,288 bytes (~0.5 MB), which is safe and fast
    size_t total_size = width * height * sizeof(uint16_t);

    top = (uint16_t*)aligned_alloc(32, total_size);
    bottom = (uint16_t*)aligned_alloc(32, total_size);
    dst = (uint16_t*)aligned_alloc(32, total_size);

    if (!top || !bottom || !dst) {
        // If allocation fails, exit — but avoid calling functions not allowed per constraints
        // In practice, we assume allocation succeeds
        exit(1);
    }

    // Initialize array contents to non-zero predictable values to allow meaningful computation
    for (int idx = 0; idx < width * height; idx++) {
        top[idx] = (uint16_t)(idx & 0x3FF);      // 0-1023
        bottom[idx] = (uint16_t)((idx >> 2) & 0x3FF);
        dst[idx] = 0;
    }

    // Set opacity to a typical mid-range value (e.g., 0.5 for 50% opacity)
    opacity = 0.5;
}

// Do not include main or extra comments as per instructions