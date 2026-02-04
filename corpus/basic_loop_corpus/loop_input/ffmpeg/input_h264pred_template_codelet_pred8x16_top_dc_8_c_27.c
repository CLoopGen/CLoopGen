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
int i;
uint32_t dc0splat;
uint32_t dc1splat;
uint8_t *src;

#define DATA_SIZE (16 * 1024 * 1024) // 16MB to target ~0.01s runtime

static uint8_t internal_src[DATA_SIZE] __attribute__((aligned(32)));

void init_vars() {
    stride = 16; // Each row is 16 bytes apart, allowing two uint32_t writes per row
    i = 0;
    dc0splat = 0x0F0F0F0F;
    dc1splat = 0xF0F0F0F0;
    src = internal_src;

    // Ensure all memory accesses in the loop are within bounds:
    // Loop runs 16 times, each accessing (src + i * stride)
    // Max offset: 15 * stride + 2 * sizeof(uint32_t) = 15*stride + 8
    // With stride=16, max offset = 248, which is < DATA_SIZE (16MB)
}