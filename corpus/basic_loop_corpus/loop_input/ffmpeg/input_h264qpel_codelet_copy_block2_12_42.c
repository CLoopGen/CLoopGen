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

#define DATA_SIZE (128 << 20) // 128 MB
#define ROWS 4096
#define ROW_SIZE (DATA_SIZE / ROWS)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcStride = ROW_SIZE;
    dstStride = ROW_SIZE;
    h = ROWS;
    i = 0;

    src_buffer = aligned_alloc(32, DATA_SIZE);
    dst_buffer = aligned_alloc(32, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        src_buffer[i] = rand() % 256;
    }

    dst = dst_buffer;
    src = src_buffer;
}