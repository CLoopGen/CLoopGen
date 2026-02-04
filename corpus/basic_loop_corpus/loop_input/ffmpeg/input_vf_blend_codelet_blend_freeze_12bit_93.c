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
    // Set dimensions for approximately 0.01 seconds runtime
    // Using moderate size: ~64MB total data, balanced between cache and memory pressure
    width = 2048;
    height = 2048;

    // Simulate typical alignment/padding: lines may be slightly wider than width
    top_linesize = width + 32 / sizeof(uint16_t);
    bottom_linesize = width + 64 / sizeof(uint16_t);
    dst_linesize = width + 16 / sizeof(uint16_t);

    size_t top_size = top_linesize * height * sizeof(uint16_t);
    size_t bottom_size = bottom_linesize * height * sizeof(uint16_t);
    size_t dst_size = dst_linesize * height * sizeof(uint16_t);

    // Allocate aligned memory to simulate image processing scenario
    top_data = (uint16_t*)aligned_alloc(64, top_size);
    bottom_data = (uint16_t*)aligned_alloc(64, bottom_size);
    dst_data = (uint16_t*)aligned_alloc(64, dst_size);

    // Initialize arrays with non-trivial but safe values
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ptrdiff_t top_idx = y * top_linesize + x;
            ptrdiff_t bottom_idx = y * bottom_linesize + x;

            top_data[top_idx] = (uint16_t)((x * 7 + y * 13) % 4096);
            // Ensure bottom[j] != 0 to avoid division by zero, but allow some near-zero values
            bottom_data[bottom_idx] = (uint16_t)(1 + ((x * 3 + y * 5) % 4095));
        }
    }

    // Initialize pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    // Opacity between 0 and 1 for realistic blending
    opacity = 0.75;

    // Zero out dst as starting point
    memset(dst_data, 0, dst_size);
}