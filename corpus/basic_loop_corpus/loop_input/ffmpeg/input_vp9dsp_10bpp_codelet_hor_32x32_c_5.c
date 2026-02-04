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

ptrdiff_t stride = 64;
uint16_t *dst;
uint16_t *left;
int y;

uint16_t dst_data[2097152]; // ~4MB, allows for 32 iterations with stride 64 (each step uses up to 28+7=35 units)
uint16_t left_data[32];

void init_vars() {
    dst = dst_data;
    left = left_data;

    for (int i = 0; i < 32; i++) {
        left[i] = (uint16_t)(i * 1234);
    }

    for (size_t i = 0; i < 2097152; i++) {
        dst_data[i] = 0;
    }
}