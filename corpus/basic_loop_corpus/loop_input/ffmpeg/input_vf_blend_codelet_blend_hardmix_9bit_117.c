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
    // Target data size ~64MB to ensure loop runtime around 0.01s on modern CPU
    const size_t target_bytes = 64 * 1024 * 1024;
    const size_t bytes_per_element = sizeof(uint16_t);
    
    // Use a reasonable width and height
    width = 2048;
    height = (target_bytes / bytes_per_element) / (3 * width); // 3 arrays: top, bottom, dst
    if (height == 0) height = 1;
    
    // Ensure minimum dimensions
    if (height < 16) height = 16;
    
    // Linesizes in units of uint16_t elements (to match ptrdiff_t usage as strides)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    opacity = 0.5; // mid-opacity
    
    // Allocate memory for the arrays
    size_t total_elements = height * width;
    top_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    bottom_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    dst_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    
    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
    
    // Initialize array contents
    for (size_t idx = 0; idx < total_elements; idx++) {
        top_data[idx] = rand() % 512;
        bottom_data[idx] = rand() % 512;
        dst_data[idx] = 0;
    }
}