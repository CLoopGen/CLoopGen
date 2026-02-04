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

static uint8_t *alloc_aligned_size(ptrdiff_t total_bytes) {
    uint8_t *ptr = aligned_alloc(32, total_bytes);
    if (!ptr) exit(1);
    return ptr;
}

void init_vars() {
    width = 1920;
    height = 1080;
    opacity = 0.75;

    top_linesize = width * sizeof(uint8_t);
    bottom_linesize = width * sizeof(uint8_t);
    dst_linesize = width * sizeof(uint8_t);

    size_t total_bytes = width * height * sizeof(uint8_t);

    top = alloc_aligned_size(total_bytes);
    bottom = alloc_aligned_size(total_bytes);
    dst = alloc_aligned_size(total_bytes);

    for (size_t idx = 0; idx < total_bytes; ++idx) {
        top[idx] = rand() % 256;
        bottom[idx] = rand() % 256;
        dst[idx] = 0;
    }
}