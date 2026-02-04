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
uint8_t *dst_dup;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static uint8_t *dst_dup_buffer;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t width = 1024;
    const size_t total_size = (size_t)block_height * width;

    src_stride = width;
    dst_stride = width;
    height = block_height;

    src_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);
    dst_dup_buffer = aligned_alloc(32, total_size);

    src = src_buffer;
    dst = dst_buffer;
    dst_dup = dst_dup_buffer;

    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = 0;
        dst_dup_buffer[i] = 0;
    }
}