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
float *top;
float *bottom;
float *dst;
double opacity;
int i;
int j;

void init_vars() {
    // Set parameters for ~0.01s runtime: use moderate size, e.g., ~10-50 MB total data
    width = 2048;
    height = 1024;

    // Simulate stride in bytes; linesize in float units (assume aligned rows)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate memory for arrays
    size_t num_elements = width * height;
    size_t alloc_size = num_elements * sizeof(float);

    top = (float*)aligned_alloc(32, alloc_size);
    bottom = (float*)aligned_alloc(32, alloc_size);
    dst = (float*)aligned_alloc(32, alloc_size);

    // Initialize with meaningful values to avoid undefined behavior
    for (size_t idx = 0; idx < num_elements; idx++) {
        top[idx] = (float)(rand() % 100) / 100.0f;      // [0.0, 1.0)
        bottom[idx] = (float)(rand() % 100) / 100.0f;   // [0.0, 1.0)
    }
}