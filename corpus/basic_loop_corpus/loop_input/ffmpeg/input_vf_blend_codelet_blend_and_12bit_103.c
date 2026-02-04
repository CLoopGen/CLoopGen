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

static uint16_t *top_data = NULL;
static uint16_t *bottom_data = NULL;
static uint16_t *dst_data = NULL;

void init_vars() {
    // Set image dimensions to achieve desired memory footprint (~64MB total)
    width = 2048;
    height = 4096;

    // Ensure linesizes are multiples of cache line and account for width
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t top_size = (size_t)height * top_linesize;
    size_t bottom_size = (size_t)height * bottom_linesize;
    size_t dst_size = (size_t)height * dst_linesize;

    // Allocate aligned memory to prevent issues and allow optimizations
    top_data = (uint16_t*)aligned_alloc(64, top_size * sizeof(uint16_t));
    bottom_data = (uint16_t*)aligned_alloc(64, bottom_size * sizeof(uint16_t));
    dst_data = (uint16_t*)aligned_alloc(64, dst_size * sizeof(uint16_t));

    if (!top_data || !bottom_data || !dst_data) {
        exit(1);
    }

    // Initialize data with non-zero values to enable meaningful computation
    for (size_t idx = 0; idx < top_size; idx++) {
        top_data[idx] = (uint16_t)(idx % 32768);
    }
    for (size_t idx = 0; idx < bottom_size; idx++) {
        bottom_data[idx] = (uint16_t)((idx * 3) % 32768);
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_data[idx] = 0;
    }

    // Assign pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    // Set opacity to a value between 0 and 1 for realistic blending
    opacity = 0.75;
}