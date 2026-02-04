#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int x86_reg;

uint8_t *src;
uint8_t *dst;
int srcWidth;
int srcHeight;
int srcStride;
int dstStride;
int x;
int y;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcWidth = 1024;
    srcHeight = 768;
    srcStride = 1024;
    dstStride = 2048;

    size_t src_size = (size_t)srcStride * (size_t)srcHeight;
    size_t dst_size = (size_t)dstStride * (size_t)(srcHeight * 2);

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    x = 0;
    y = 0;
}