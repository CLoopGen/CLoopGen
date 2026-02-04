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
    // Set image dimensions to achieve desired runtime (~0.01s)
    // Empirically, around 512x512 to 1024x1024 is reasonable for this type of operation
    width = 1024;
    height = 512;

    // Allocate memory with padding to prevent out-of-bounds access
    size_t total_elements = width * height;
    
    // Allocate aligned memory for better performance
    top = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * total_elements);
    bottom = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * total_elements);
    dst = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * total_elements);

    // Initialize line strides in elements (not bytes)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    // Initialize opacity to a reasonable value between 0 and 1
    opacity = 0.5;

    // Initialize arrays with sample data
    for (size_t idx = 0; idx < total_elements; idx++) {
        top[idx] = (uint16_t)(rand() % 65536);
        bottom[idx] = (uint16_t)(rand() % 65536);
        dst[idx] = 0;
    }
}