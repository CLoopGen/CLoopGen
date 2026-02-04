#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *dst;
uint8_t *src;
int width;
int height;
ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int i;
int j;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024ULL)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    height = 4096;
    width = 4096;
    stride_src = width + 32;
    stride_dst = width + 32;

    size_t buffer_size = (size_t)height * (size_t)stride_src;
    if (buffer_size < TOTAL_BYTES) {
        buffer_size = TOTAL_BYTES;
    }

    src_buffer = aligned_alloc(64, buffer_size);
    dst_buffer = aligned_alloc(64, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    dst = dst_buffer;
    src = src_buffer;

    i = 0;
    j = 0;
}