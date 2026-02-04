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

void init_vars() {
    width = 1024;
    height = 512;
    opacity = 0.75;

    top_linesize = width * sizeof(uint16_t);
    bottom_linesize = width * sizeof(uint16_t);
    dst_linesize = width * sizeof(uint16_t);

    size_t total_size = width * height * sizeof(uint16_t);

    top = (uint16_t*)aligned_alloc(32, total_size);
    bottom = (uint16_t*)aligned_alloc(32, total_size);
    dst = (uint16_t*)aligned_alloc(32, total_size);

    for (size_t idx = 0; idx < width * height; idx++) {
        top[idx] = rand() % 512;
        bottom[idx] = rand() % 512;
    }
}