#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int h;
uint8_t *cm;
int i;
int j;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;
static uint8_t internal_cm_buffer[256];

void init_vars() {
    w = 1024;
    h = 1024;
    srcStride = w + 4;
    dstStride = w;

    size_t src_size = (h + 4) * srcStride;
    size_t dst_size = h * dstStride;

    internal_src_buffer = aligned_alloc(32, src_size);
    internal_dst_buffer = aligned_alloc(32, dst_size);

    src = internal_src_buffer + 2 * srcStride + 2;
    dst = internal_dst_buffer;

    for (size_t idx = 0; idx < src_size; idx++) {
        internal_src_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        internal_dst_buffer[idx] = 0;
    }
    for (int idx = 0; idx < 256; idx++) {
        internal_cm_buffer[idx] = idx;
    }

    cm = internal_cm_buffer;
}