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
float *top;
float *bottom;
float *dst;
double opacity;
int i;
int j;

static float *top_buffer = NULL;
static float *bottom_buffer = NULL;
static float *dst_buffer = NULL;

void init_vars() {
    // Set image dimensions to achieve desired memory access and runtime
    width = 2048;
    height = 128;

    // Simulate stride (linesize) to include some padding for realism
    top_linesize = width + 16;
    bottom_linesize = width + 32;
    dst_linesize = width + 8;

    opacity = 0.75;

    // Allocate memory with padding to avoid out-of-bounds access
    size_t top_size = height * top_linesize * sizeof(float);
    size_t bottom_size = height * bottom_linesize * sizeof(float);
    size_t dst_size = height * dst_linesize * sizeof(float);

    top_buffer = (float*)aligned_alloc(32, top_size);
    bottom_buffer = (float*)aligned_alloc(32, bottom_size);
    dst_buffer = (float*)aligned_alloc(32, dst_size);

    if (!top_buffer || !bottom_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero to ensure defined behavior
    memset(top_buffer, 0, top_size);
    memset(bottom_buffer, 0, bottom_size);
    memset(dst_buffer, 0, dst_size);

    // Assign pointers
    top = top_buffer;
    bottom = bottom_buffer;
    dst = dst_buffer;
}

// Cleanup function to free allocated memory
void free_vars() {
    if (top_buffer) {
        free(top_buffer);
        top_buffer = NULL;
    }
    if (bottom_buffer) {
        free(bottom_buffer);
        bottom_buffer = NULL;
    }
    if (dst_buffer) {
        free(dst_buffer);
        dst_buffer = NULL;
    }
}