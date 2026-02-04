#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

#define DATA_SIZE (64 * 1024 * 1024)

static uint8_t src_buffer[DATA_SIZE];
static uint8_t dst_buffer[DATA_SIZE];

void init_vars() {
    const int block_height = 16384;
    const int bytes_per_row = 4;
    h = block_height;
    srcStride = bytes_per_row;
    dstStride = bytes_per_row;

    src = src_buffer;
    dst = dst_buffer;

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }
}