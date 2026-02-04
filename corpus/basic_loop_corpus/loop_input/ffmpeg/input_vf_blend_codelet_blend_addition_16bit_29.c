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

void init_vars() {
    // Set image dimensions to achieve ~100ms runtime
    // Assume processing ~1e8 pixels per second, so aim for ~10e6 pixels
    width = 4096;
    height = 2048;
    
    // Ensure each line size is in units of uint16_t elements
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    opacity = 0.75; // Arbitrary valid opacity between 0 and 1
    
    // Allocate memory for arrays
    size_t total_elements = width * height;
    size_t total_bytes = total_elements * sizeof(uint16_t);
    
    top = (uint16_t*)aligned_alloc(32, total_bytes);
    bottom = (uint16_t*)aligned_alloc(32, total_bytes);
    dst = (uint16_t*)aligned_alloc(32, total_bytes);
    
    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize arrays with sample data
    for (size_t idx = 0; idx < total_elements; idx++) {
        top[idx] = (uint16_t)(idx % 50000);
        bottom[idx] = (uint16_t)((idx * 7) % 50000);
    }
}