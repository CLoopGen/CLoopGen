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

#define DATA_SIZE (128 << 20) // 128 MB
#define ROW_WIDTH (64 * sizeof(uint16_t)) // 128 bytes per row (32 uint16_t)
#define NUM_ROWS (DATA_SIZE / ROW_WIDTH)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    h = NUM_ROWS;
    srcStride = ROW_WIDTH;
    dstStride = ROW_WIDTH;

    src_buffer = aligned_alloc(64, DATA_SIZE);
    dst_buffer = aligned_alloc(64, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE; i++) {
        src_buffer[i] = rand() % 256;
    }

    dst = dst_buffer;
    src = src_buffer;
}