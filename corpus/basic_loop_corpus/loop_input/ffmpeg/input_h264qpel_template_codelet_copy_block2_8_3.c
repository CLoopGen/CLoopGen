#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Allocate buffers with sufficient size
    src_buffer = aligned_alloc(32, DATA_SIZE);
    dst_buffer = aligned_alloc(32, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = rand() & 0xFF;
    }

    // Set up parameters
    h = DATA_SIZE / 2; // Each iteration copies 2 bytes, so we copy half the buffer
    dstStride = 2;
    srcStride = 2;

    // Initialize pointers to start of buffers
    dst = dst_buffer;
    src = src_buffer;
}