#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(uint64_t)
#define ROWS (DATA_SIZE_MB * 1024 * 1024 / ELEMENT_SIZE)
#define STRIDE (ELEMENT_SIZE)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcStride = STRIDE;
    dstStride = STRIDE;
    h = ROWS;

    src_buffer = aligned_alloc(8, ROWS * srcStride);
    dst_buffer = aligned_alloc(8, ROWS * dstStride);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (int idx = 0; idx < ROWS * srcStride; idx++) {
        src_buffer[idx] = rand() % 256;
    }

    src = src_buffer;
    dst = dst_buffer;
}