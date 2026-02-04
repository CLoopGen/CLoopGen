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

#define DATA_SIZE (128 << 20) // 128 MB
#define ROW_SIZE (64)
#define STRIDE (ROW_SIZE)
#define HEIGHT (DATA_SIZE / ROW_SIZE)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    src_buffer = aligned_alloc(64, DATA_SIZE);
    dst_buffer = aligned_alloc(64, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        src_buffer[idx] = rand() % 256;
    }

    dst = dst_buffer;
    src = src_buffer;
    dstStride = STRIDE;
    srcStride = STRIDE;
    h = HEIGHT;
    i = 0;
}