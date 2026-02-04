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
#define ROW_WIDTH (64)
#define ALIGNMENT 64

static uint8_t *aligned_src_buffer;
static uint8_t *aligned_dst_buffer;

void init_vars() {
    const size_t total_size = DATA_SIZE;
    const size_t row_bytes = ROW_WIDTH * sizeof(uint16_t); // 128 bytes per row in terms of uint16_t x 64

    posix_memalign((void**)&aligned_src_buffer, ALIGNMENT, total_size);
    posix_memalign((void**)&aligned_dst_buffer, ALIGNMENT, total_size);

    src = aligned_src_buffer;
    dst = aligned_dst_buffer;

    srcStride = row_bytes;
    dstStride = row_bytes;

    h = total_size / row_bytes;

    for (size_t i = 0; i < total_size; ++i) {
        aligned_src_buffer[i] = rand() % 256;
    }

    i = 0;
}