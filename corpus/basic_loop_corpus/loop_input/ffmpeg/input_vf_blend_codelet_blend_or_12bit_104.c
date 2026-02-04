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

static uint16_t *top_data;
static uint16_t *bottom_data;
static uint16_t *dst_data;

void init_vars() {
    // Target: make loop take ~0.01 seconds
    // Assume modern CPU can do ~1e9 operations/sec -> aim for ~1e7 operations
    // Each inner loop iteration does several arithmetic ops; estimate 10 per pixel
    // So aim for ~1e6 pixels

    width = 2048;
    height = 512;  // Total elements: 2048 * 512 = 1,048,576 (~1M)

    // Linesizes in bytes are typically aligned (e.g., to 32-byte boundaries)
    // But here linesize is in units of ptrdiff_t and used as array stride -> likely in elements or bytes?
    // Given usage: `dst += dst_linesize`, and dst is uint16_t*, linesize should be in number of elements
    // However, common practice is linesize in bytes. But code uses `j < width` with `dst[j]` so if linesize is in bytes,
    // pointer arithmetic would be wrong unless scaled.

    // Since `dst[j]` is used and then `dst += dst_linesize`, and dst is uint16_t*,
    // then dst_linesize must be in number of uint16_t elements per row (i.e., stride in elements).
    // So we set linesize equal to width to have contiguous rows.

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.5;  // arbitrary value between 0 and 1

    // Allocate image data
    size_t num_elements = width * height;
    size_t data_size_bytes = num_elements * sizeof(uint16_t);

    top_data = aligned_alloc(32, data_size_bytes);
    bottom_data = aligned_alloc(32, data_size_bytes);
    dst_data = aligned_alloc(32, data_size_bytes);

    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize input data with non-zero values to ensure meaningful computation
    for (size_t idx = 0; idx < num_elements; idx++) {
        top_data[idx] = (uint16_t)(idx % 32768);
        bottom_data[idx] = (uint16_t)((idx * 7) % 32768);
        dst_data[idx] = 0;
    }

    // Set pointers to start of data
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}