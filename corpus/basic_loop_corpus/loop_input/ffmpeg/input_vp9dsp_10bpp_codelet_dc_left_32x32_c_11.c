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
uint64_t dc;
int y;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime
static uint16_t buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 32; // 32 elements = 64 bytes per row, allows 8 writes of 8 bytes each safely within bounds
    dst = buffer;
    dc = 0x123456789ABCDEF0ULL;
    y = 0;
}