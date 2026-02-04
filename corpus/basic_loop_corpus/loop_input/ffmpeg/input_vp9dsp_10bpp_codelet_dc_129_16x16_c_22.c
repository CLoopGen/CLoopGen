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

#define DATA_SIZE (128 << 20) // 128 MB
static uint16_t data[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 16; // ensures 4x u64 writes fit within row
    dst = data;
    val = 0x123456789ABCDEF0ULL;
    y = 0;
}