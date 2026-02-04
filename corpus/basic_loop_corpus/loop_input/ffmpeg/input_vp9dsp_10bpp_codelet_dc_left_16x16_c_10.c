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

static uint16_t *dst_buffer;
static ptrdiff_t effective_stride;

void init_vars() {
    const size_t total_data_size = 16 * 256 * 1024; // ~256KB of data (safe for cache effects, avoids huge strides)
    dst_buffer = (uint16_t*)aligned_alloc(64, total_data_size);
    if (!dst_buffer) {
        exit(1);
    }

    // Ensure stride is at least the width of 16 uint16_t elements (32 bytes), aligned to cache line
    effective_stride = 16; // number of uint16_t between rows
    stride = effective_stride;

    dst = dst_buffer;
    dc = 0x123456789ABCDEF0ULL;
    y = 0;
}