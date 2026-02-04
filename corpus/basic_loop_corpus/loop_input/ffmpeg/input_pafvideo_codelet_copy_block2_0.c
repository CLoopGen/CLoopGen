#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB
#define ROW_WIDTH 256
#define NUM_ROWS (DATA_SIZE / ROW_WIDTH)

static uint8_t src_buffer[DATA_SIZE];
static uint8_t dst_buffer[DATA_SIZE];

void init_vars() {
    h = NUM_ROWS;
    srcStride = ROW_WIDTH;
    dstStride = ROW_WIDTH;

    src = src_buffer;
    dst = dst_buffer;

    for (int i = 0; i < DATA_SIZE; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
}