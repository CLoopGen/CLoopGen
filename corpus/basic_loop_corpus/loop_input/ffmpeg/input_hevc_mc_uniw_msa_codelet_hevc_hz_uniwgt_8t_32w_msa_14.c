#include <stdint.h>
#include <stdlib.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    height = 65536;
    src_stride = 64;
    dst_stride = 64;

    size_t src_size = (size_t)(height * 2) * src_stride;
    size_t dst_size = (size_t)(height * 2) * dst_stride;

    src_buffer = (uint8_t*)aligned_alloc(64, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        abort();
    }

    for (size_t i = 0; i < src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; ++i) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}