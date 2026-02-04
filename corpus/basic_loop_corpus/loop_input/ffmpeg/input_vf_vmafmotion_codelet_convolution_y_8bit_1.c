#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *filter;
int filt_w = 5;
uint16_t *dst;
int w = 1024;
int h = 1024;
uint8_t *src;
ptrdiff_t src_stride = 1024;
ptrdiff_t dst_stride = 1024;
int radius = 2;
int borders_top = 10;
int i, j, k, sum;

void init_vars() {
    filter = aligned_alloc(32, filt_w * sizeof(uint16_t));
    src = aligned_alloc(32, h * src_stride * sizeof(uint8_t));
    dst = aligned_alloc(32, h * dst_stride * sizeof(uint16_t));

    for (int idx = 0; idx < filt_w; idx++) {
        filter[idx] = (uint16_t)(idx + 1) * 51;
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            src[y * src_stride + x] = (uint8_t)((x + y) & 0xFF);
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            dst[y * dst_stride + x] = 0;
        }
    }
}