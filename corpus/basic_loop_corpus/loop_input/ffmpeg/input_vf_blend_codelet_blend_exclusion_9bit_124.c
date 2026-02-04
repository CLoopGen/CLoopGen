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
    height = 512;

    // Simulate typical stride alignment (in bytes, then convert to element count)
    ptrdiff_t alignment = 64 / sizeof(uint16_t); // 64-byte alignment
    top_linesize    = (width + alignment - 1) & ~(alignment - 1);
    bottom_linesize = (width + alignment - 1) & ~(alignment - 1);
    dst_linesize    = (width + alignment - 1) & ~(alignment - 1);

    // Allocate memory with padding for safe access within loop bounds
    size_t top_size    = top_linesize    * height;
    size_t bottom_size = bottom_linesize * height;
    size_t dst_size    = dst_linesize    * height;

    top    = (uint16_t*)aligned_alloc(alignment * sizeof(uint16_t), top_size    * sizeof(uint16_t));
    bottom = (uint16_t*)aligned_alloc(alignment * sizeof(uint16_t), bottom_size * sizeof(uint16_t));
    dst    = (uint16_t*)aligned_alloc(alignment * sizeof(uint16_t), dst_size    * sizeof(uint16_t));

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize array contents
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            top[y * top_linesize + x]    = rand() % 512;
            bottom[y * bottom_linesize + x] = rand() % 512;
        }
    }

    // Initialize scalar parameters
    opacity = 0.75;

    // Ensure no garbage in dst
    memset(dst, 0, dst_size * sizeof(uint16_t));
}