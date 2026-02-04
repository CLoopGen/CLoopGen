#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t buffer_size;

void init_vars() {
    height = 65536;
    stride = 16;
    buffer_size = (size_t)height * (size_t)stride;

    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = (uint8_t)((i + 64) & 0xFF);
    }

    src = src_buffer;
    dst = dst_buffer;
}