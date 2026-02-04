#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size = 1 << 20; // 1MB data size

void init_vars() {
    stride = 64;
    src_buffer = (uint8_t*)aligned_alloc(64, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, total_size);
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }
    src = src_buffer;
    dst = dst_buffer;
    loop_cnt = 4;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}