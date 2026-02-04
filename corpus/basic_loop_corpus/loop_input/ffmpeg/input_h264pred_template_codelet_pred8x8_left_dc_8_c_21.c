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
uint8_t *src;

#define DATA_SIZE (64 * 1024 * 1024)  // 64MB to ensure ~0.01s runtime on modern CPU

static uint8_t internal_src[DATA_SIZE];

void init_vars() {
    stride = 16;  // Ensure alignment and safe access for 2 uint32_t writes per row
    dc0splat = 0xdeadbeefU;
    src = internal_src;
}
