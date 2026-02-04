#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int h;
uint8_t *cm;
int i;
int j;

static uint8_t *internal_dst;
static uint8_t *internal_src;
static uint8_t *internal_cm;

void init_vars() {
    w = 1024;
    h = 512;
    srcStride = w + 4;
    dstStride = w;

    size_t src_size = (h + 4) * srcStride;
    size_t dst_size = h * dstStride;
    size_t cm_size = 256;

    internal_src = aligned_alloc(32, src_size);
    internal_dst = aligned_alloc(32, dst_size);
    internal_cm  = aligned_alloc(32, cm_size);

    src = internal_src + (2 * srcStride) + 2;
    dst = internal_dst;

    for (size_t idx = 0; idx < src_size; idx++) {
        internal_src[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        internal_dst[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < cm_size; idx++) {
        internal_cm[idx] = rand() & 0xFF;
    }

    cm = internal_cm;

    i = 0;
    j = 0;
}