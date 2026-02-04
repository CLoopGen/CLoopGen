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
    // Set dimensions to achieve ~64MB of total data usage
    width = 2048;
    height = 8192;
    
    // Ensure linesize accounts for padding or alignment if needed; here we assume contiguous rows
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    opacity = 0.75; // Arbitrary opacity value between 0 and 1
    
    // Allocate memory for the arrays: each is width*height in size
    size_t num_elements = width * height;
    size_t alloc_size = num_elements * sizeof(uint16_t);
    
    top = (uint16_t*)aligned_alloc(64, alloc_size);
    bottom = (uint16_t*)aligned_alloc(64, alloc_size);
    dst = (uint16_t*)aligned_alloc(64, alloc_size);
    
    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize top and bottom with sample data to avoid undefined behavior
    for (i = 0; i < num_elements; i++) {
        top[i] = rand() % 1024;    // Values from 0 to 1023
        bottom[i] = rand() % 1024;
    }
}