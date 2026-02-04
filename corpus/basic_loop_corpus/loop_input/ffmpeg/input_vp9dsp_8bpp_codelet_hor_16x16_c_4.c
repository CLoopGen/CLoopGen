#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
uint8_t *dst;
uint8_t *left;
int y;

#define DATA_SIZE (64 * 1024 * 1024)  // 64MB to ensure loop runs ~0.01s

static uint8_t *dst_buffer;
static uint8_t *left_buffer;

void init_vars() {
    stride = 16;  // Ensure each row is 16-byte aligned and spaced

    dst_buffer = (uint8_t *)aligned_alloc(32, DATA_SIZE);
    left_buffer = (uint8_t *)aligned_alloc(16, 16);

    if (!dst_buffer || !left_buffer) {
        exit(1);
    }

    dst = dst_buffer;
    left = left_buffer;

    for (int i = 0; i < 16; i++) {
        left[i] = (uint8_t)(i * 15);  // arbitrary initialization
    }
}

void cleanup_vars() {
    if (dst_buffer) free(dst_buffer);
    if (left_buffer) free(left_buffer);
}