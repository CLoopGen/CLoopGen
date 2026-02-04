#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

uint16_t *dst;
uint16_t *src;
int h;
int stride;
int scale;
unsigned int dc;
int i;

static uint16_t *src_buffer;
static uint16_t *dst_buffer;
static size_t total_size;

void init_vars() {
    total_size = (1 << 20) / sizeof(uint16_t); // ~1MB of data
    h = 50000; // Adjust to ensure runtime ~0.01s
    stride = 4;
    scale = 123;
    dc = 456;

    src_buffer = aligned_alloc(32, total_size * sizeof(uint16_t));
    dst_buffer = aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint16_t)(idx & 0xFFFF);
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}