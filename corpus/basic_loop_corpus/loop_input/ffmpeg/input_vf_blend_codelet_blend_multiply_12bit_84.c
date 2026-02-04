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

void init_vars() {
    // Set image dimensions to achieve desired data size
    height = (DATA_SIZE_MB * 1024 * 1024) / (3 * sizeof(uint16_t) * 512); // Estimate for ~64MB total
    height = (height < 1) ? 1 : height;
    width = 512; // Fixed width for predictable row size

    // Ensure each line has enough space for width elements and possible alignment padding
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    // Allocate memory for arrays
    top = aligned_alloc(64, height * top_linesize * sizeof(uint16_t));
    bottom = aligned_alloc(64, height * bottom_linesize * sizeof(uint16_t));
    dst = aligned_alloc(64, height * dst_linesize * sizeof(uint16_t));

    // Initialize array data
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            top[y * top_linesize + x] = rand() % 4096;
            bottom[y * bottom_linesize + x] = rand() % 4096;
        }
    }

    // Initialize scalar values
    opacity = 0.5;
    i = 0;
    j = 0;
}