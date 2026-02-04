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
    // Target: ~0.01 seconds runtime -> aim for moderate data size, say ~32-64MB total
    // Let's choose 512x512 pixels per image (height x width)
    width = 512;
    height = 512;

    // Ensure linesizes are at least width, possibly with padding; use width for simplicity
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75; // arbitrary value between 0 and 1

    // Allocate memory for each plane: 512*512 elements of uint16_t = 512*512*2 bytes = 512KB each
    size_t num_elements = width * height;
    size_t data_size = num_elements * sizeof(uint16_t);

    top_data = (uint16_t*)aligned_alloc(32, data_size);
    bottom_data = (uint16_t*)aligned_alloc(32, data_size);
    dst_data = (uint16_t*)aligned_alloc(32, data_size);

    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize top and bottom with sample data: gradients to ensure varied values
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            size_t idx = y * width + x;
            top_data[idx] = (uint16_t)((x * y) % 65536);
            bottom_data[idx] = (uint16_t)(((x + y) * 123) % 65536);
        }
    }

    // Initialize dst to zero
    memset(dst_data, 0, data_size);

    // Set pointers to start of data
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}

// Cleanup function to avoid memory leaks (not required but good practice)
void cleanup_vars() {
    free(top_data);
    free(bottom_data);
    free(dst_data);
}