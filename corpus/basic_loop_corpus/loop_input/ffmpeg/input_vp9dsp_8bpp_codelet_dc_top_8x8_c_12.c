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
uint32_t dc;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB to target ~0.01 sec runtime
static uint8_t global_dst_buffer[DATA_SIZE];

void init_vars() {
    stride = 16; // reasonable small stride, multiple of alignment
    dst = global_dst_buffer;
    dc = 0xdeadbeef; // arbitrary non-zero pattern
    y = 0;
}