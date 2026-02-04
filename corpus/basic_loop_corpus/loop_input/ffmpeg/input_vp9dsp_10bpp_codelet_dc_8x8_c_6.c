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

static uint16_t *dst_base;
static size_t total_size = 64 * 1024 * 1024; // ~64MB to ensure sufficient runtime (~0.01s target)

void init_vars() {
    stride = 16; 

    dst_base = aligned_alloc(64, total_size);
    if (!dst_base) {
        exit(1);
    }

    dst = dst_base;

    dc = 0x123456789ABCDEF0ULL;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_base);
}