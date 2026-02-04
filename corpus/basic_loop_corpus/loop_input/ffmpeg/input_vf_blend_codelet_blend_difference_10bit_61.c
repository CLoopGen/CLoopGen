#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    width = 1024;
    height = 512;
    opacity = 0.5;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = (size_t)width * height * sizeof(uint16_t);

    top = (uint16_t*)aligned_alloc(32, total_size);
    bottom = (uint16_t*)aligned_alloc(32, total_size);
    dst = (uint16_t*)aligned_alloc(32, total_size);

    for (size_t idx = 0; idx < (size_t)width * height; idx++) {
        top[idx] = (uint16_t)(idx % 65536);
        bottom[idx] = (uint16_t)((idx * 3) % 65536);
    }
}