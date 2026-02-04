#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

#define DATA_SIZE_MB 64
#define LINE_WIDTH (16) // 4 * sizeof(uint8_t) * 4 accesses per row
#define LINES (DATA_SIZE_MB * 1024 * 1024 / LINE_WIDTH)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    h = LINES;
    srcStride = LINE_WIDTH;
    dstStride = LINE_WIDTH;

    size_t total_size = (size_t)h * LINE_WIDTH;

    src_buffer = (uint8_t*)aligned_alloc(16, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(16, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    memset(dst_buffer, 0, total_size);

    src = src_buffer;
    dst = dst_buffer;
}