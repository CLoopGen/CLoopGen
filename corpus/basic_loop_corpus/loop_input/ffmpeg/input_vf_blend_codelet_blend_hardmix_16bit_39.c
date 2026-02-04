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

static uint16_t *top_buffer;
static uint16_t *bottom_buffer;
static uint16_t *dst_buffer;

void init_vars() {
    // Set image dimensions to achieve desired computation load
    width = 2048;
    height = 128;
    
    // Compute linesizes in units of uint16_t
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    // Allocate memory for buffers
    size_t total_size = width * height * sizeof(uint16_t);
    
    top_buffer = (uint16_t*)aligned_alloc(32, total_size);
    bottom_buffer = (uint16_t*)aligned_alloc(32, total_size);
    dst_buffer = (uint16_t*)aligned_alloc(32, total_size);
    
    // Initialize with valid data
    for (size_t idx = 0; idx < width * height; idx++) {
        top_buffer[idx] = (uint16_t)(idx % 65536);
        bottom_buffer[idx] = (uint16_t)((idx * 3) % 65536);
        dst_buffer[idx] = 0;
    }
    
    // Set pointers to start of buffers
    top = top_buffer;
    bottom = bottom_buffer;
    dst = dst_buffer;
    
    // Set opacity to a reasonable value between 0 and 1
    opacity = 0.75;
    
    // Initialize loop counters
    i = 0;
    j = 0;
}