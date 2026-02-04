#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint8_t *src;
ptrdiff_t src_stride;
int height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static int buffer_size;

void init_vars() {
    buffer_size = 64 * 1024 * 1024; // 64 MB of data
    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (int i = 0; i < buffer_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src_stride = 1024;
    dst_stride = 1024;
    height = 1024;

    src = src_buffer;
    dst = dst_buffer;
}