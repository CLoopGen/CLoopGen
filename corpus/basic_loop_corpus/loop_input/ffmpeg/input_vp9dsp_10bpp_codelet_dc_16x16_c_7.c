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

#define DATA_SIZE (16 * 1024 * 1024) // ~16MB to target ~0.01s runtime
static uint16_t buffer[DATA_SIZE];

void init_vars() {
    stride = 16; // ensures 16 uint16_t elements per row, matching 4x u64 writes
    dst = buffer;
    dc = 0x123456789ABCDEF0ULL;
    y = 0;
}