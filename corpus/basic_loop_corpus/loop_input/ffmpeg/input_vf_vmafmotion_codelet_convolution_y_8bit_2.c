#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *filter;
int filt_w;
uint16_t *dst;
int w;
uint8_t *src;
ptrdiff_t src_stride;
ptrdiff_t dst_stride;
int radius;
int borders_top;
int borders_bottom;
int i;
int j;
int k;
int sum;

void init_vars() {
    w = 2048;
    filt_w = 17;
    radius = filt_w / 2;
    borders_top = radius;
    borders_bottom = borders_top + 1024;

    src_stride = w;
    dst_stride = w;

    size_t src_size = (borders_bottom + radius) * src_stride * sizeof(uint8_t);
    size_t dst_size = borders_bottom * dst_stride * sizeof(uint16_t);
    size_t filter_size = filt_w * sizeof(uint16_t);

    src = (uint8_t*)aligned_alloc(32, src_size);
    dst = (uint16_t*)aligned_alloc(32, dst_size);
    filter = (uint16_t*)aligned_alloc(32, filter_size);

    for (int idx = 0; idx < filt_w; idx++) {
        filter[idx] = 256 / filt_w + ((idx % 7) * 31); 
    }

    for (int y = 0; y < (borders_bottom + radius); y++) {
        for (int x = 0; x < w; x++) {
            src[y * src_stride + x] = (y + x) % 256;
        }
    }

    for (int y = 0; y < borders_bottom; y++) {
        for (int x = 0; x < w; x++) {
            dst[y * dst_stride + x] = 0;
        }
    }
}