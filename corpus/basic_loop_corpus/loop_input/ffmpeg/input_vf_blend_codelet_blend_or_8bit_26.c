#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *top;
ptrdiff_t top_linesize;
uint8_t *bottom;
ptrdiff_t bottom_linesize;
uint8_t *dst;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
double opacity;
int i;
int j;

#define DATA_SIZE_MB 64

static uint8_t *alloc_aligned_buffer(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        return NULL;
    }
    return (uint8_t*)ptr;
}

void init_vars() {
    // Set dimensions to process approximately DATA_SIZE_MB of data per plane
    width = 1920;
    height = (DATA_SIZE_MB * 1024 * 1024) / (width * 3); // Estimate for 3 planes
    if (height == 0) height = 1;
    // Clamp height to reasonable range
    if (height > 1080) height = 1080;

    // Ensure total data is roughly target size
    ptrdiff_t actual_data_per_row = width;
    top_linesize = (actual_data_per_row + 31) & ~31; // Align to 32-byte boundary
    bottom_linesize = top_linesize;
    dst_linesize = top_linesize;

    size_t buffer_size = top_linesize * height;

    uint8_t *top_data = alloc_aligned_buffer(buffer_size);
    uint8_t *bottom_data = alloc_aligned_buffer(buffer_size);
    uint8_t *dst_data = alloc_aligned_buffer(buffer_size);

    // Initialize with non-zero patterns to allow inspection
    for (size_t i = 0; i < buffer_size; i++) {
        top_data[i] = (uint8_t)(i & 0xFF);
        bottom_data[i] = (uint8_t)((i * 3) & 0xFF);
        dst_data[i] = 0;
    }

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    opacity = 0.75;

    i = 0;
    j = 0;
}