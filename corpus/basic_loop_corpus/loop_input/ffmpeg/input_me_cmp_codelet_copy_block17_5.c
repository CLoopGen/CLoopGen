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
#define HEIGHT (DATA_SIZE / ROW_SIZE)

static uint8_t *src_data;
static uint8_t *dst_data;

void init_vars() {
    srcStride = ROW_SIZE;
    dstStride = ROW_SIZE;
    h = HEIGHT;
    i = 0;

    src_data = aligned_alloc(32, DATA_SIZE);
    dst_data = aligned_alloc(32, DATA_SIZE);

    if (!src_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_data[idx] = (uint8_t)(idx & 0xFF);
    }

    dst = dst_data;
    src = src_data;
}