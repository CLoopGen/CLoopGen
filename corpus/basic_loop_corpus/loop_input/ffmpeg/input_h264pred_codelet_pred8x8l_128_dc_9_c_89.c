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
static size_t total_size = 64 * 1024 * 1024; // ~64MB to ensure non-trivial runtime (~0.01s range)

void init_vars() {
    src_buffer = (uint16_t*)aligned_alloc(64, total_size);
    if (!src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = 1024; // Large enough stride to simulate row stepping in 2D layout
    src = src_buffer;

    for (size_t i = 0; i < total_size / sizeof(uint16_t); i++) {
        src_buffer[i] = (uint16_t)(i & 0xFFFF);
    }
}