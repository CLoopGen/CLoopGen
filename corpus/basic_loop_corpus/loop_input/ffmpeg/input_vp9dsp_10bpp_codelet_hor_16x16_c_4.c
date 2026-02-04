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
uint16_t *left;
int y;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static uint16_t internal_dst[DATA_SIZE / sizeof(uint16_t)];
static uint16_t internal_left[16];

void init_vars() {
    stride = 16; // ensures dst moves by 16 uint16_t elements per iteration
    dst = internal_dst;
    left = internal_left;

    // Initialize left with non-zero values for meaningful computation
    for (int i = 0; i < 16; i++) {
        left[i] = (uint16_t)(i + 1) * 1000;
    }

    // Initialize dst memory to zero to avoid garbage
    for (size_t i = 0; i < DATA_SIZE / sizeof(uint16_t); i++) {
        internal_dst[i] = 0;
    }
}