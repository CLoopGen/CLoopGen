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
    // Set image dimensions
    width = 2048;
    height = 128;

    // Calculate linesizes in elements (not bytes), ensure alignment-friendly
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    // Allocate memory for the arrays, ensuring no overlap and proper bounds
    size_t total_size = width * height * sizeof(uint16_t);

    top_data = (uint16_t*)aligned_alloc(32, total_size);
    bottom_data = (uint16_t*)aligned_alloc(32, total_size);
    dst_data = (uint16_t*)aligned_alloc(32, total_size);

    if (!top_data || !bottom_data || !dst_data) {
        exit(1);
    }

    // Initialize pointers to start of allocated blocks
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    // Initialize with valid data to prevent undefined behavior
    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (uint16_t)(idx % 32768);
        bottom_data[idx] = (uint16_t)((idx * 3) % 32768);
        dst_data[idx] = 0;
    }

    // Set opacity to a reasonable value between 0.0 and 1.0
    opacity = 0.5;

    // Ensure loop counters are initialized by caller, but reset here for safety
    i = 0;
    j = 0;
}