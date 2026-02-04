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
    // Set reasonable dimensions to achieve ~0.01s runtime
    // Empirical testing suggests around 10-20 million pixels is sufficient
    width = 2048;
    height = 4096;
    
    // Ensure linesizes are at least width, possibly with padding
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    opacity = 0.75; // Arbitrary valid opacity between 0 and 1
    
    // Allocate memory for arrays
    size_t total_elements = width * height;
    size_t data_size = total_elements * sizeof(uint16_t);
    
    top_data = (uint16_t*)aligned_alloc(64, data_size);
    bottom_data = (uint16_t*)aligned_alloc(64, data_size);
    dst_data = (uint16_t*)aligned_alloc(64, data_size);
    
    // Initialize with plausible values
    for (size_t idx = 0; idx < total_elements; idx++) {
        top_data[idx] = (uint16_t)(idx % 512);  // Values from 0 to 511
        bottom_data[idx] = (uint16_t)((idx * 7) % 1024); // Some other distribution
        dst_data[idx] = 0;
    }
    
    // Set pointers to start of allocated regions
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}