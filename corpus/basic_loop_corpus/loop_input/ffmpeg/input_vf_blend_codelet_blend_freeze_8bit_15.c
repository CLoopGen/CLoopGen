#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
#define ALIGNMENT 32

static uint8_t *alloc_aligned_buffer(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, ALIGNMENT, size) != 0) {
        return NULL;
    }
    return (uint8_t*)ptr;
}

void init_vars() {
    width = 1920;
    height = 1080;
    opacity = 0.5;
    top_linesize = (width + 15) & ~15;
    bottom_linesize = (width + 15) & ~15;
    dst_linesize = (width + 15) & ~15;

    size_t total_size = height * dst_linesize;

    uint8_t *top_data = alloc_aligned_buffer(total_size);
    uint8_t *bottom_data = alloc_aligned_buffer(total_size);
    uint8_t *dst_data = alloc_aligned_buffer(total_size);

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            top_data[y * top_linesize + x] = (uint8_t)((x * y) % 256);
            bottom_data[y * bottom_linesize + x] = (uint8_t)((x + y + 1) % 256);
            if (bottom_data[y * bottom_linesize + x] == 0) {
                bottom_data[y * bottom_linesize + x] = 1;
            }
        }
    }

    memset(dst_data, 0, total_size);
}