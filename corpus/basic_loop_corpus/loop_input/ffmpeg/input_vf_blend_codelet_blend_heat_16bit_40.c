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

#define DATA_SIZE_MB 64

void init_vars() {
    // Set parameters to achieve roughly 64MB of total data processing
    width = 2048;
    height = 8192;
    
    // Ensure each row fits within reasonable memory stride
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    opacity = 0.5; // default opacity between 0 and 1
    
    // Allocate memory for top, bottom, and dst
    size_t total_elements = width * height;
    size_t total_bytes = total_elements * sizeof(uint16_t);
    
    top = (uint16_t*)aligned_alloc(32, total_bytes);
    bottom = (uint16_t*)aligned_alloc(32, total_bytes);
    dst = (uint16_t*)aligned_alloc(32, total_bytes);
    
    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize top and bottom with non-uniform data to exercise the conditional logic
    for (size_t idx = 0; idx < total_elements; idx++) {
        // Simulate some typical pixel-like values in 16-bit range
        top[idx] = (uint16_t)((idx * 73) % 65536);
        bottom[idx] = (uint16_t)((idx * 137) % 65536);
    }
}