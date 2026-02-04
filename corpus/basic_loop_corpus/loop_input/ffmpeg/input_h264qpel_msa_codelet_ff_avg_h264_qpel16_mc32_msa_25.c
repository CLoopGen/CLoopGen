#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t row;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size = 1 << 20; // 1MB data size

void init_vars() {
    stride = 64;
    src_buffer = aligned_alloc(64, total_size);
    dst_buffer = aligned_alloc(64, total_size);
    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
}