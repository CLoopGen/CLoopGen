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
    // Set image dimensions to achieve desired runtime (~0.01s)
    // Based on typical performance estimates, use ~32MB of data
    width = 2048;
    height = 4096;
    
    // Ensure linesizes are multiples of width but allow padding if needed
    // For simplicity, set linesize in elements (not bytes), and assume no extra padding
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    // Allocate memory for three arrays: top, bottom, dst
    size_t total_elements = width * height;
    size_t total_bytes = total_elements * sizeof(uint16_t);
    
    top_data = (uint16_t*)aligned_alloc(64, total_bytes);
    bottom_data = (uint16_t*)aligned_alloc(64, total_bytes);
    dst_data = (uint16_t*)aligned_alloc(64, total_bytes);
    
    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize data with non-trivial values to avoid division by zero
    for (size_t idx = 0; idx < total_elements; idx++) {
        top_data[idx] = (uint16_t)(rand() % 4096); // 0-4095 range
        bottom_data[idx] = (uint16_t)(rand() % 4096);
        // Avoid exact zero in top to prevent div-by-zero; ensure at least 1
        if (top_data[idx] == 0) top_data[idx] = 1;
    }
    
    // Assign pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
    
    // Set opacity to a mid-range value
    opacity = 0.5;
}