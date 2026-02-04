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

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB to ensure ~0.01s runtime
static uint8_t global_dst[DATA_SIZE];

void init_vars() {
    stride = 32; // Each row advances by 32 bytes (8 uint32_t writes of 4 bytes each)
    dst = global_dst;
    val = 0xDEADBEEF;
    y = 0;
}