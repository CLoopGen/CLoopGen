#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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

#define DATA_SIZE_MB 64

void init_vars() {
    // Set dimensions to achieve ~64MB of data processed
    height = (DATA_SIZE_MB * (1 << 20)) / (3 * sizeof(uint16_t) * 512); // Estimate for width
    if (height < 1) height = 1;
    width = 512;

    // Adjust so total data is roughly target size
    while (height * width * 3 * sizeof(uint16_t) > DATA_SIZE_MB * (1 << 20)) {
        if (height > 1) {
            height--;
        } else {
            width--;
        }
    }

    // Ensure minimum sizes
    if (height < 1) height = 1;
    if (width < 1) width = 1;

    // Line strides in elements (not bytes), allow padding if needed
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate aligned memory for performance and safety
    top = aligned_alloc(32, height * top_linesize * sizeof(uint16_t));
    bottom = aligned_alloc(32, height * bottom_linesize * sizeof(uint16_t));
    dst = aligned_alloc(32, height * dst_linesize * sizeof(uint16_t));

    // Initialize arrays with non-trivial but safe values
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ptrdiff_t idx = y * top_linesize + x;
            top[idx] = (uint16_t)((x * 789 + y * 321) % 512);
            bottom[idx] = (uint16_t)((x * 567 + y * 123) % 512 + 1); // Avoid zero to prevent div0
        }
    }

    // Initialize loop counters
    i = 0;
    j = 0;
}