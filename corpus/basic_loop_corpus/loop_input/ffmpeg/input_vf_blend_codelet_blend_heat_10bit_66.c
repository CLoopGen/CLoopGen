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
    // Set dimensions to achieve desired computation load
    // Aim for ~100ms runtime: use moderate size with enough arithmetic intensity
    width = 1024;
    height = 512;

    // Ensure linesizes are multiples of alignment and account for row padding if needed
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate memory for arrays
    size_t total_size = width * height * sizeof(uint16_t);

    top_data = (uint16_t*)aligned_alloc(32, total_size);
    bottom_data = (uint16_t*)aligned_alloc(32, total_size);
    dst_data = (uint16_t*)aligned_alloc(32, total_size);

    // Initialize data with non-trivial values to exercise the expression
    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (uint16_t)(rand() % 1024);
        bottom_data[idx] = (uint16_t)(rand() % 1024);
        dst_data[idx] = 0;
    }

    // Point the external pointers to the allocated buffers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}

// Cleanup function to avoid memory leaks (not required by problem, but good practice)
void cleanup_vars() {
    free(top_data);
    free(bottom_data);
    free(dst_data);
}