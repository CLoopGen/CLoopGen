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
    // Target: make the loop take ~0.01 seconds
    // Estimate: simple arithmetic per pixel, modern CPU does ~1e9 ops/sec
    // Aim for ~10M pixels to be safe within 0.01 sec range

    width = 2048;
    height = 512;

    // Ensure total data is around 20-30 MB range (3 channels * width * height * 2 bytes)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t top_size = height * top_linesize * sizeof(uint16_t);
    size_t bottom_size = height * bottom_linesize * sizeof(uint16_t);
    size_t dst_size = height * dst_linesize * sizeof(uint16_t);

    top_data = aligned_alloc(32, top_size);
    bottom_data = aligned_alloc(32, bottom_size);
    dst_data = aligned_alloc(32, dst_size);

    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    opacity = 0.75;

    // Initialize input data to non-zero values to avoid degenerate math
    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (uint16_t)(idx % 32768);
        bottom_data[idx] = (uint16_t)((idx * 3) % 32768);
    }

    // Ensure dst is zeroed to have defined output
    memset(dst_data, 0, dst_size);
}