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
    // Set dimensions to achieve ~100ms runtime
    // Assume modern CPU can do ~1e9 operations/sec, inner loop has ~10-20 operations
    // Target ~1e7 operations -> 3000x3000 pixels is about 9e6 iterations
    width = 3000;
    height = 3000;

    // Allocate lines with padding to prevent overlap
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = width * height * sizeof(uint16_t);

    // Use malloc and assign to non-const pointers first
    top_data = (uint16_t*)aligned_alloc(32, total_size);
    bottom_data = (uint16_t*)aligned_alloc(32, total_size);
    dst_data = (uint16_t*)aligned_alloc(32, total_size);

    // Initialize data with non-zero values to ensure meaningful computation
    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (uint16_t)(idx % 65536);
        bottom_data[idx] = (uint16_t)((idx * 7) % 65536);
        dst_data[idx] = 0;
    }

    // Assign to external pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    // Set opacity to a fractional value
    opacity = 0.8;

    // Ensure all variables are properly initialized
    i = 0;
    j = 0;
}