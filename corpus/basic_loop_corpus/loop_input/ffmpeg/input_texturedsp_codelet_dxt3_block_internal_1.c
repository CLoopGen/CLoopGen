#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
ptrdiff_t stride;
uint8_t *block;
int x;
int y;
uint32_t colors[4];
uint32_t code;

static uint8_t *dst_buffer;
static uint8_t *block_buffer;

void init_vars() {
    stride = 4 * 4;
    code = 0xFFFFFFFF;

    colors[0] = 0x112233;
    colors[1] = 0x445566;
    colors[2] = 0x778899;
    colors[3] = 0xAABBCC;

    dst_buffer = calloc(1, 4 * stride);
    if (!dst_buffer) exit(1);
    dst = dst_buffer;

    block_buffer = calloc(1, 8);
    if (!block_buffer) exit(1);
    block = block_buffer;

    for (int i = 0; i < 8; i++) {
        block[i] = (uint8_t)(0xAA + i);
    }
}