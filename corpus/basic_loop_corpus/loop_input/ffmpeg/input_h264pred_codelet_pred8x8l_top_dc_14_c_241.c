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

static uint16_t *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime
    buffer = (uint16_t*)aligned_alloc(64, buffer_size * sizeof(uint16_t));
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        buffer[i] = (uint16_t)(i & 0xFFFF);
    }

    src = buffer;
    stride = 8; // ensures we stay within bounds over 8 iterations
    dc = 0x0123456789ABCDEFULL;
    y = 0;
}