#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB
#define ROW_SIZE 32
#define ROWS (DATA_SIZE / ROW_SIZE)

static uint8_t src_data[DATA_SIZE];
static uint8_t dst_data[DATA_SIZE];

void init_vars() {
    h = ROWS;
    i = 0;

    srcStride = ROW_SIZE;
    dstStride = ROW_SIZE;

    src = src_data;
    dst = dst_data;
}