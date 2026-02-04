#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
int i;

#define DATA_SIZE (64 << 20) // 64 MB of data
#define ROWS (DATA_SIZE / 4)
#define STRIDE 4

static uint8_t src_buffer[DATA_SIZE] __attribute__((aligned(1)));
static uint8_t dst_buffer[DATA_SIZE] __attribute__((aligned(1)));

void init_vars() {
    for (size_t j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = (uint8_t)(j & 0xFF);
    }

    src = src_buffer;
    dst = dst_buffer;
    srcStride = STRIDE;
    dstStride = STRIDE;
    h = ROWS;
    i = 0;
}