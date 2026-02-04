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

static float *top_data;
static float *bottom_data;
static float *dst_data;

void init_vars() {
    // Set parameters for ~0.01s runtime: aim for ~16-32 million elements based on typical performance
    width = 4096;
    height = 4096;
    
    // Allocate data with padding to prevent overflow during loop access
    size_t total_elements = width * height;
    
    // Allocate aligned memory to ensure proper alignment and avoid undefined behavior
    top_data = aligned_alloc(32, total_elements * sizeof(float));
    bottom_data = aligned_alloc(32, total_elements * sizeof(float));
    dst_data = aligned_alloc(32, total_elements * sizeof(float));
    
    // Initialize arrays with meaningful data
    for (size_t idx = 0; idx < total_elements; idx++) {
        top_data[idx] = (float)(idx % 256) * 0.5f;
        bottom_data[idx] = (float)(idx % 128) * 0.7f;
        dst_data[idx] = 0.0f;
    }
    
    // Set linesizes in bytes per row (stride), assuming contiguous rows
    ptrdiff_t line_bytes = width * sizeof(float);
    
    // Ensure linesize is in number of elements (not bytes) as used in pointer arithmetic
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    // Attach pointers to start of data
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
    
    // Set opacity to a mid-range value
    opacity = 0.75;
    
    // Zero loop indices
    i = 0;
    j = 0;
}

// Cleanup function to avoid memory leaks in long-running environments
void cleanup_vars() {
    if (top_data) free(top_data);
    if (bottom_data) free(bottom_data);
    if (dst_data) free(dst_data);
}