#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define TOTAL_BYTES (128 * 1024 * 1024) // Aim for ~128MB of total data

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
    // Set image dimensions to achieve desired memory footprint
    width = 2048;
    height = 1536; // Total pixels: ~3.1M, scales with bytes per pixel

    // Each line size in bytes divided by sizeof(uint16_t)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate aligned memory to prevent issues and allow optimizations
    size_t row_elements = width;
    size_t num_elements = height * row_elements;
    size_t total_bytes_top = num_elements * sizeof(uint16_t);
    size_t total_bytes_bottom = num_elements * sizeof(uint16_t);
    size_t total_bytes_dst = num_elements * sizeof(uint16_t);

    // Ensure we are near the target memory usage
    if (total_bytes_top + total_bytes_bottom + total_bytes_dst > TOTAL_BYTES) {
        // Scale down if needed - but our current setup is about 3 * 2048*1536*2 = ~18.9MB
        // Which is within range, so no scaling needed.
    }

    top = aligned_alloc(32, num_elements * sizeof(uint16_t));
    bottom = aligned_alloc(32, num_elements * sizeof(uint16_t));
    dst = aligned_alloc(32, num_elements * sizeof(uint16_t));

    // Initialize arrays with non-zero predictable patterns to allow compiler to not optimize away
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            size_t idx = y * row_elements + x;
            top[idx] = (uint16_t)(x ^ y);
            bottom[idx] = (uint16_t)((x * 73 + y * 101) % 1024);
            dst[idx] = 0;
        }
    }
}