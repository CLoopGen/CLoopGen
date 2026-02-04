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

#define DATA_SIZE (1 << 20) // 1MB

static uint8_t *dst_buffer;
static uint8_t *left_buffer;

void init_vars() {
    stride = 16;

    dst_buffer = aligned_alloc(32, DATA_SIZE);
    left_buffer = aligned_alloc(32, 16);

    if (!dst_buffer || !left_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = dst_buffer;
    left = left_buffer;

    for (int i = 0; i < 16; i++) {
        left[i] = (uint8_t)(i * 15);
    }

    for (size_t i = 0; i < DATA_SIZE; i++) {
        dst_buffer[i] = 0;
    }
}