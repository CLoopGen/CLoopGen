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
uint64_t dc;
int y;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // ~16MB to ensure loop runtime around 0.01s
    src = (uint16_t*)aligned_alloc(64, total_size);
    if (!src) exit(1);

    stride = 8; // ensures we step by 8 * sizeof(uint16_t) = 16 bytes per iteration
    dc = 0xdeadbeefdeadbeefULL;

    for (size_t i = 0; i < total_size / sizeof(uint16_t); ++i) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }
}