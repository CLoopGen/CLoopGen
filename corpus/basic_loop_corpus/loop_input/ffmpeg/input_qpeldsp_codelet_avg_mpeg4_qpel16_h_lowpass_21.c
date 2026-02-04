#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
uint8_t *cm;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t cm_buffer[256];

void init_vars() {
    const int width = 17;
    h = 100000;
    srcStride = 32;
    dstStride = 32;

    size_t src_size = (size_t)h * srcStride;
    size_t dst_size = (size_t)h * dstStride;

    dst_buffer = aligned_alloc(32, dst_size);
    src_buffer = aligned_alloc(32, src_size);

    dst = dst_buffer;
    src = src_buffer;

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = rand() & 0xFF;
    }
    for (int idx = 0; idx < 256; idx++) {
        cm_buffer[idx] = rand() & 0xFF;
    }

    cm = cm_buffer;
}