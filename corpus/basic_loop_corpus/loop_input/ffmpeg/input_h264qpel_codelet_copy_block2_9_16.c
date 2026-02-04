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

#define DATA_SIZE (64 << 20) // 64 MB of data
#define ROWS 16384
#define STRIDE 4096

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcStride = STRIDE;
    dstStride = STRIDE;
    h = ROWS;
    i = 0;

    posix_memalign((void**)&src_buffer, 16, (size_t)srcStride * (size_t)h);
    posix_memalign((void**)&dst_buffer, 16, (size_t)dstStride * (size_t)h);

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < (size_t)srcStride * (size_t)h; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
}