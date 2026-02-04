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

#define DATA_SIZE_MB 64

static uint16_t *top_data = NULL;
static uint16_t *bottom_data = NULL;
static uint16_t *dst_data = NULL;

void init_vars() {
    // Set image dimensions to achieve desired runtime
    width = 2048;
    height = 8192 / 2;  // Approx. 8K x 4K equivalent processing
    
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;
    
    opacity = 0.5;
    
    size_t total_elements = width * height;
    size_t total_bytes = total_elements * sizeof(uint16_t);
    
    top_data = (uint16_t*)aligned_alloc(32, total_bytes);
    bottom_data = (uint16_t*)aligned_alloc(32, total_bytes);
    dst_data = (uint16_t*)aligned_alloc(32, total_bytes);
    
    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
    
    // Initialize arrays with non-trivial values to exercise the conditional logic
    for (size_t idx = 0; idx < total_elements; idx++) {
        top_data[idx] = (uint16_t)((idx * 7 + 11) % 4096);
        bottom_data[idx] = (uint16_t)((idx * 13 + 17) % 4096);
        dst_data[idx] = 0;
    }
}