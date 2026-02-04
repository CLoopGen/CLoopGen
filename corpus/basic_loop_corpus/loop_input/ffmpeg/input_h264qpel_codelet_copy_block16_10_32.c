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
#define BLOCK_WIDTH (16 * sizeof(uint16_t)) // 4 quadwords of 8 bytes each: 16 uint16_ts
#define ALIGNMENT 64

static uint8_t *aligned_src_buffer;
static uint8_t *aligned_dst_buffer;

void init_vars() {
    posix_memalign((void**)&aligned_src_buffer, ALIGNMENT, DATA_SIZE + BLOCK_WIDTH);
    posix_memalign((void**)&aligned_dst_buffer, ALIGNMENT, DATA_SIZE + BLOCK_WIDTH);

    src = aligned_src_buffer;
    dst = aligned_dst_buffer;

    srcStride = BLOCK_WIDTH;
    dstStride = BLOCK_WIDTH;

    h = DATA_SIZE / BLOCK_WIDTH;

    for (size_t idx = 0; idx < DATA_SIZE + BLOCK_WIDTH; ++idx) {
        aligned_src_buffer[idx] = rand() & 0xFF;
    }
}