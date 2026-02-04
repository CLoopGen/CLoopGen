#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size = 64 * (1 << 20); // 64 MB

void init_vars() {
    stride = 64;
    total_size = 64 * (1 << 20);

    src_buffer = (uint8_t*)aligned_alloc(64, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, total_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    loop_cnt = 0;
}