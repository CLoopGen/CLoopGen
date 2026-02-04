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

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime
static uint16_t buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 32; // Advance by 32 uint16_t elements per row (64 bytes)
    dst = buffer;
    val = 0x123456789ABCDEF0ULL;
    y = 0;

    // Ensure that we don't exceed buffer bounds: 32 iterations * stride must leave room for 28 + 8 = 36 elements at last step
    // Each iteration accesses up to offset 28 (7th element of 8), so need space for at least 36 elements past base
    // With stride=32 and 32 rows, total used = 32*32 + 36 = 1060 uint16_t entries -> well under buffer size
}