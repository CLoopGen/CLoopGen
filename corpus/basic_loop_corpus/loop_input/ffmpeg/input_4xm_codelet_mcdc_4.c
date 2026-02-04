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
    total_size = 64 * 1024 * 1024; // ~128MB of data (each element is 2 bytes, two arrays)
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
    h = total_size / 2;  // Each iteration processes one 32-bit word (2x uint16_t), so half the buffer size
    stride = 2;           // Advance by 2 uint16_t elements per row (i.e., 4 bytes)
    scale = 2;            // Arbitrary non-zero scale factor
    dc = 0x1000;          // Constant DC offset
    i = 0;
}