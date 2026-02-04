#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
float *top;
float *bottom;
float *dst;
double opacity;
int i;
int j;

void init_vars() {
    width = 2048;
    height = 128;
    opacity = 0.5;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = width * height * sizeof(float);

    top = (float *)aligned_alloc(32, total_size);
    bottom = (float *)aligned_alloc(32, total_size);
    dst = (float *)aligned_alloc(32, total_size);

    for (size_t idx = 0; idx < width * height; idx++) {
        top[idx] = (float)(idx % 256) / 255.0f;
        bottom[idx] = (float)((255 - idx) % 256) / 255.0f;
        dst[idx] = 0.0f;
    }
}