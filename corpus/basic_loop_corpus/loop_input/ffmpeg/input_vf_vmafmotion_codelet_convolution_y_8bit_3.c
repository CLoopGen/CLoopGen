#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *filter;
int filt_w = 5;
uint16_t *dst;
int w = 2048;
int h = 2048;
uint8_t *src;
ptrdiff_t src_stride = 2048;
ptrdiff_t dst_stride = 2048;
int radius = 2;
int borders_bottom = 0;
int i, j, k, sum;

void init_vars() {
    filter = aligned_alloc(32, filt_w * sizeof(uint16_t));
    src = aligned_alloc(32, h * src_stride * sizeof(uint8_t));
    dst = aligned_alloc(32, h * dst_stride * sizeof(uint16_t));

    for (int idx = 0; idx < filt_w; idx++) {
        filter[idx] = (uint16_t)(rand() % 256);
    }

    for (int idx = 0; idx < h * src_stride; idx++) {
        src[idx] = (uint8_t)(rand() % 256);
    }

    for (int idx = 0; idx < h * dst_stride; idx++) {
        dst[idx] = 0;
    }
}