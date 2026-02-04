#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint16_t *filter;
int filt_w = 5;
uint16_t *dst;
int w = 1024;
int h = 1024;
uint16_t *src;
ptrdiff_t src_stride = 1024;
ptrdiff_t dst_stride = 1024;
int radius = 2;
int borders_top = 10;
int i, j, k, sum;

void init_vars() {
    const size_t src_size = (size_t)h * src_stride;
    const size_t dst_size = (size_t)(borders_top + h) * dst_stride; // Allow space for output
    const int filter_size = filt_w;

    src = aligned_alloc(32, src_size * sizeof(uint16_t));
    dst = aligned_alloc(32, dst_size * sizeof(uint16_t));
    filter = aligned_alloc(32, filter_size * sizeof(uint16_t));

    if (!src || !dst || !filter) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src[idx] = rand() & 0x3FF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst[idx] = 0;
    }
    for (int idx = 0; idx < filt_w; idx++) {
        filter[idx] = (rand() % 200) + 1;
    }

    radius = filt_w / 2;
    borders_top = radius;
}