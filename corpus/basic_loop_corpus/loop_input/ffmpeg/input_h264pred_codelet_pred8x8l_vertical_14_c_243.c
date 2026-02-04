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

int y;
uint16_t *src;
int stride;
uint64_t a = 0xAAAAAAAAAAAAAAAA;
uint64_t b = 0xBBBBBBBBBBBBBBBB;

static uint16_t *internal_src;
static int internal_stride;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB to ensure ~0.01s runtime
    internal_src = aligned_alloc(64, total_size * sizeof(uint16_t));
    if (!internal_src) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        internal_src[i] = (uint16_t)(i & 0xFFFF);
    }

    internal_stride = 2048; 

    src = internal_src;
    stride = internal_stride;
}