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

uint16_t *src;
int stride;
int y;

static uint16_t *src_buffer;
static size_t total_size = 64 * 1024 * 1024; // ~64MB to ensure sufficient runtime (~0.01s target)

void init_vars() {
    if ((stride % 8) != 0) {
        stride = 8; // Ensure alignment and safe pointer arithmetic
    }

    src_buffer = (uint16_t *)aligned_alloc(64, total_size);
    if (!src_buffer) {
        exit(1);
    }

    src = src_buffer;
}