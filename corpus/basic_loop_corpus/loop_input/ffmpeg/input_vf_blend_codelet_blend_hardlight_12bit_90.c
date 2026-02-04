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
    // Set parameters for approximately 0.01 seconds runtime on modern CPU
    // Aim for moderate data size: ~64-128MB total, balanced with loop overhead
    width = 2048;
    height = 128;
    
    // Simulate typical alignment padding (e.g., image stride)
    dst_linesize = width + 16;
    top_linesize = width + 8;
    bottom_linesize = width + 24;
    
    opacity = 0.75;
    
    // Allocate aligned memory to avoid false sharing and ensure safety
    size_t top_size = height * top_linesize * sizeof(uint16_t);
    size_t bottom_size = height * bottom_linesize * sizeof(uint16_t);
    size_t dst_size = height * dst_linesize * sizeof(uint16_t);
    
    top_data = (uint16_t*)aligned_alloc(64, top_size);
    bottom_data = (uint16_t*)aligned_alloc(64, bottom_size);
    dst_data = (uint16_t*)aligned_alloc(64, dst_size);
    
    if (!top_data || !bottom_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
    
    // Initialize arrays with non-trivial but valid values
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            top[y * top_linesize + x] = (uint16_t)((x * 31 + y * 17) % 4096);
            bottom[y * bottom_linesize + x] = (uint16_t)((x * 13 + y * 29) % 4096);
            dst[y * dst_linesize + x] = 0;
        }
    }
}