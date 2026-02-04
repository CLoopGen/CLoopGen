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
    // Set dimensions to process approximately 64 MB of data
    width = 2048;
    height = 8192;
    
    // Ensure each line is padded to multiple of 16 bytes for realistic alignment
    ptrdiff_t line_bytes = width * sizeof(uint16_t);
    top_linesize = line_bytes / sizeof(uint16_t);
    bottom_linesize = line_bytes / sizeof(uint16_t);
    dst_linesize = line_bytes / sizeof(uint16_t);

    // Allocate memory for arrays
    size_t total_bytes = width * height * sizeof(uint16_t);
    
    top = (uint16_t*)aligned_alloc(32, total_bytes);
    bottom = (uint16_t*)aligned_alloc(32, total_bytes);
    dst = (uint16_t*)aligned_alloc(32, total_bytes);

    // Initialize arrays with non-zero but valid data
    for (size_t idx = 0; idx < width * height; idx++) {
        top[idx] = (uint16_t)(idx % 512);
        bottom[idx] = (uint16_t)((idx * 7) % 512);
    }

    // Set opacity to a typical blending value
    opacity = 0.75;
}

// Explicitly allow linking with externally defined loop
void loop();