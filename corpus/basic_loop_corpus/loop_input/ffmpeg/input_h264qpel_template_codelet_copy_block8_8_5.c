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

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data
#define ROWS 8192
#define ROW_WIDTH (DATA_SIZE / ROWS)

static uint8_t src_data[DATA_SIZE];
static uint8_t dst_data[DATA_SIZE];

void init_vars() {
    h = ROWS;
    srcStride = ROW_WIDTH;
    dstStride = ROW_WIDTH;

    src = src_data;
    dst = dst_data;

    i = 0;

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        src_data[idx] = (uint8_t)(idx & 0xFF);
    }
}