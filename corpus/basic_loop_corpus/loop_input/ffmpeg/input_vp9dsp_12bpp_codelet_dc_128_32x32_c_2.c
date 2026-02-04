#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
uint16_t *dst;
uint64_t val;
int y;

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB to ensure ~0.01s runtime
static uint16_t data_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 32; // Advance by 32 uint16_t elements per iteration (64 bytes)
    dst = data_buffer;
    val = 0x123456789ABCDEF0ULL;
    y = 0;
}