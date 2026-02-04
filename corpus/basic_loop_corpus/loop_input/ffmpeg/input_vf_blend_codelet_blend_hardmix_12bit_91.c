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

#define TOTAL_DATA_SIZE (128 << 20) // Aim for ~128 MB of total data

void init_vars() {
    opacity = 0.5;
    height = 1024;
    width = 1024;

    top_linesize = width * sizeof(uint16_t);
    bottom_linesize = width * sizeof(uint16_t);
    dst_linesize = width * sizeof(uint16_t);

    size_t array_size = width * height * sizeof(uint16_t);

    top = aligned_alloc(32, array_size);
    bottom = aligned_alloc(32, array_size);
    dst = aligned_alloc(32, array_size);

    for (size_t idx = 0; idx < (size_t)(width * height); idx++) {
        top[idx] = rand() % 4096;
        bottom[idx] = rand() % 4096;
        dst[idx] = 0;
    }
}