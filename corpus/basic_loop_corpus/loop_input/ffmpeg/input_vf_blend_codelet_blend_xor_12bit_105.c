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
    // Target approximately 0.01 seconds runtime: use ~16-32 million pixels
    width = 4096;
    height = 4096;
    
    // Ensure non-zero linesizes for proper stride (in elements)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    opacity = 0.75; // arbitrary value between 0 and 1
    
    // Allocate memory for arrays with padding if needed
    size_t total_elements = width * height;
    size_t total_bytes = total_elements * sizeof(uint16_t);
    
    top_data = (uint16_t*)aligned_alloc(32, total_bytes);
    bottom_data = (uint16_t*)aligned_alloc(32, total_bytes);
    dst_data = (uint16_t*)aligned_alloc(32, total_bytes);
    
    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize input data with non-zero values for meaningful computation
    for (size_t idx = 0; idx < total_elements; idx++) {
        top_data[idx] = (uint16_t)(idx % 32768);
        bottom_data[idx] = (uint16_t)((idx * 3) % 32768);
        dst_data[idx] = 0;
    }
    
    // Set pointers to start of allocated buffers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}