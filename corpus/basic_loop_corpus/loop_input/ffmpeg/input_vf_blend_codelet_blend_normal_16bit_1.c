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

void init_vars() {
    // Set image dimensions to achieve ~0.01s runtime
    // Empirical testing suggests around 1-2 million pixels gives ~0.01s on modern CPUs
    width = 1280;
    height = 512;
    
    // Calculate linesizes in bytes, then convert to element count for uint16_t
    ptrdiff_t top_pitch = width * sizeof(uint16_t);
    ptrdiff_t bottom_pitch = width * sizeof(uint16_t);
    ptrdiff_t dst_pitch = width * sizeof(uint16_t);
    
    // Ensure alignment padding if needed (none required here, using tight packing)
    top_linesize = top_pitch / sizeof(uint16_t);
    bottom_linesize = bottom_pitch / sizeof(uint16_t);
    dst_linesize = dst_pitch / sizeof(uint16_t);
    
    // Allocate buffers with proper sizes including linesize padding per row
    size_t top_size = top_linesize * height;
    size_t bottom_size = bottom_linesize * height;
    size_t dst_size = dst_linesize * height;
    
    top = (uint16_t*)aligned_alloc(32, top_size * sizeof(uint16_t));
    bottom = (uint16_t*)aligned_alloc(32, bottom_size * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, dst_size * sizeof(uint16_t));
    
    // Initialize data to prevent undefined behavior
    for (size_t idx = 0; idx < top_size; idx++) {
        top[idx] = rand() % 65536;
    }
    for (size_t idx = 0; idx < bottom_size; idx++) {
        bottom[idx] = rand() % 65536;
    }
    
    // Initialize opacity to a reasonable value between 0 and 1
    opacity = 0.75;
    
    // Zero output buffer
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst[idx] = 0;
    }
}