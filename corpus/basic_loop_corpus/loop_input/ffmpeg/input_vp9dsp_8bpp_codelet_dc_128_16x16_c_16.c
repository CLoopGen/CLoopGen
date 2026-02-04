#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
uint8_t *dst;
uint32_t val;
int y;

uint8_t *dst_buffer;

void init_vars() {
    val = 0xdeadbeef;
    stride = 16;
    size_t buffer_size = 16 * 16; // 16 rows, each accessed with stride
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    if (!dst_buffer) {
        exit(1);
    }
    dst = dst_buffer;
}