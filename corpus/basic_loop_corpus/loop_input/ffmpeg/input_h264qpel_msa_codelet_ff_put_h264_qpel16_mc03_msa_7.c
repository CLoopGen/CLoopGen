#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size = 64 << 20; // 64 MB for sufficient runtime (~0.01 sec on modern CPU)

void init_vars() {
    stride = 16;

    src_buffer = (uint8_t *)aligned_alloc(32, total_size);
    dst_buffer = (uint8_t *)aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}