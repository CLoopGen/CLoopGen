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
    // Set image dimensions to achieve desired runtime (~0.01s)
    // Empirical tuning: ~10 million pixels gives reasonable timing
    width = 3200;
    height = 800;
    
    // Line sizes in bytes, aligned to 32-byte boundary for potential vectorization
    ptrdiff_t line_bytes = (width * sizeof(uint16_t) + 31) & ~31;
    top_linesize = line_bytes / sizeof(uint16_t);
    bottom_linesize = line_bytes / sizeof(uint16_t);
    dst_linesize = line_bytes / sizeof(uint16_t);
    
    size_t buffer_size = dst_linesize * height * sizeof(uint16_t);
    
    // Allocate aligned buffers
    top_buffer = aligned_alloc(32, buffer_size);
    bottom_buffer = aligned_alloc(32, buffer_size);
    dst_buffer = aligned_alloc(32, buffer_size);
    
    // Initialize with non-zero predictable patterns
    for (size_t idx = 0; idx < width * height; idx++) {
        top_buffer[idx] = (uint16_t)(idx % 50000);
        bottom_buffer[idx] = (uint16_t)((idx * 7) % 50000);
    }
    
    // Zero out destination
    memset(dst_buffer, 0, buffer_size);
    
    // Set pointers to start
    top = top_buffer;
    bottom = bottom_buffer;
    dst = dst_buffer;
    
    // Opacity between 0 and 1 for realistic blending
    opacity = 0.75;
    
    // Initialize loop counters
    i = 0;
    j = 0;
}