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

static uint16_t *top_data;
static uint16_t *bottom_data;
static uint16_t *dst_data;

void init_vars() {
    // Set opacity to a typical blending value
    opacity = 0.75;

    // Target execution time ~0.01 seconds: aim for moderate data size
    // Based on typical performance, use ~32MB total data
    // Use width and height such that total pixels is reasonable
    width = 2048;
    height = 2048;

    // Linesizes in units of ptrdiff_t (typically bytes/sizeof(uint16_t))
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    // Allocate memory for the arrays
    size_t num_elements = width * height;
    size_t data_size = num_elements * sizeof(uint16_t);

    top_data = (uint16_t*)aligned_alloc(32, data_size);
    bottom_data = (uint16_t*)aligned_alloc(32, data_size);
    dst_data = (uint16_t*)aligned_alloc(32, data_size);

    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize top and bottom with sample data
    for (size_t idx = 0; idx < num_elements; idx++) {
        top_data[idx] = rand() % 4096;
        bottom_data[idx] = rand() % 4096;
    }

    // Set pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}