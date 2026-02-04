#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static int32_t total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

void init_vars() {
    src_stride = 1024;
    dst_stride = 1024;
    height = 256 * 1024; // ensures (height >> 2) is large enough

    size_t src_size = (size_t)(height >> 2) * 4 * src_stride + 3 * src_stride;
    size_t dst_size = (size_t)(height >> 2) * 4 * dst_stride + 3 * dst_stride;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    cnt = 0;
}