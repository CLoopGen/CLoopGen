#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *filter;
int filt_w = 17; // typical filter width (e.g., for a kernel with radius)

uint16_t *dst;
int w = 2048; // width of the image
ptrdiff_t dst_stride = 2048;

uint16_t *src;
ptrdiff_t src_stride = 2048;

int radius = 8;
int borders_top = 0;
int borders_bottom = 2048;

int i, j, k, sum;

void init_vars() {
    const size_t src_size = (size_t)(borders_bottom + radius) * src_stride;
    const size_t dst_size = (size_t)borders_bottom * dst_stride;
    const size_t filter_size = (size_t)filt_w;

    src = aligned_alloc(32, src_size * sizeof(uint16_t));
    dst = aligned_alloc(32, dst_size * sizeof(uint16_t));
    filter = aligned_alloc(32, filter_size * sizeof(uint16_t));

    for (size_t idx = 0; idx < src_size; idx++) {
        src[idx] = rand() & 0x3FF; // random 10-bit values
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst[idx] = 0;
    }
    int half_filter = filt_w / 2;
    for (int idx = 0; idx < filt_w; idx++) {
        int dist = (idx - half_filter);
        filter[idx] = (1024 / (1 + dist*dist)) & 0xFFFF; // simple inverse square kernel, scaled
    }

    borders_top = radius;
    borders_bottom = borders_bottom - radius; // ensure we don't go out of bounds in src

    src_stride = w;
    dst_stride = w;
}