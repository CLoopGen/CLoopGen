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

#define DATA_SIZE (128 << 20) // 128 MB

static uint16_t internal_dst[DATA_SIZE / sizeof(uint16_t)];
static uint16_t internal_left[8];

void init_vars() {
    stride = 8; // Ensure sufficient spacing between dst rows
    dst = internal_dst;
    left = internal_left;
    y = 0;

    for (int i = 0; i < 8; i++) {
        left[i] = (uint16_t)(i + 1) * 1000;
    }

    for (size_t i = 0; i < DATA_SIZE / sizeof(uint16_t); i++) {
        internal_dst[i] = 0;
    }
}