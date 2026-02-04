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
    width = 2048;
    height = 128;

    opacity = 0.75;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_elements = (size_t)height * width;

    top = aligned_alloc(32, total_elements * sizeof(uint16_t));
    bottom = aligned_alloc(32, total_elements * sizeof(uint16_t));
    dst = aligned_alloc(32, total_elements * sizeof(uint16_t));

    for (size_t idx = 0; idx < total_elements; idx++) {
        top[idx] = rand() % 65536;
        bottom[idx] = rand() % 65536;
        dst[idx] = 0;
    }
}