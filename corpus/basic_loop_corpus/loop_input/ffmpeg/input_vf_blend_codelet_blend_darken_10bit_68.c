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
    // Set image dimensions
    width = 1024;
    height = 512;

    // Calculate linesizes in bytes and convert to element count (since we're using uint16_t)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    // Allocate memory for arrays: total size ~ 1024 * 512 * 2 * 3 = ~3MB, which is reasonable
    size_t num_elements = width * height;
    top = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));
    bottom = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));

    // Initialize array data with non-zero values to allow meaningful computation
    for (size_t idx = 0; idx < num_elements; idx++) {
        top[idx] = rand() % 65536;
        bottom[idx] = rand() % 65536;
    }

    // Set opacity to a mid-range value between 0 and 1
    opacity = 0.5;

    // Ensure initial pointers are set correctly; loop will update them per row
    // Base pointers are already correct as they point to the start of allocated memory
}