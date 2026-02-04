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
#define ROW_SIZE 16
#define ALIGNMENT 64

static uint8_t *aligned_src_buffer;
static uint8_t *aligned_dst_buffer;

void init_vars() {
    posix_memalign((void**)&aligned_src_buffer, ALIGNMENT, DATA_SIZE + ROW_SIZE);
    posix_memalign((void**)&aligned_dst_buffer, ALIGNMENT, DATA_SIZE + ROW_SIZE);

    src = aligned_src_buffer;
    dst = aligned_dst_buffer;

    for (size_t j = 0; j < DATA_SIZE + ROW_SIZE; j++) {
        aligned_src_buffer[j] = rand() & 0xFF;
        aligned_dst_buffer[j] = 0;
    }

    srcStride = ROW_SIZE;
    dstStride = ROW_SIZE;
    h = DATA_SIZE / ROW_SIZE;
    i = 0;
}