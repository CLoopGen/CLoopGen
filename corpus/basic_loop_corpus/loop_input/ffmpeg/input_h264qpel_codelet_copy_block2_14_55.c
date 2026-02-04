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

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime estimate
#define ROWS 4096
#define ROW_SIZE (DATA_SIZE / ROWS)

static uint8_t src_buffer[DATA_SIZE];
static uint8_t dst_buffer[DATA_SIZE];

void init_vars() {
    // Initialize source and destination arrays
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
        dst_buffer[idx] = 0;
    }

    // Set up striding: copy full rows with stride to next row
    srcStride = ROW_SIZE;
    dstStride = ROW_SIZE;
    h = ROWS;
    i = 0;

    // Pointers to buffers
    src = src_buffer;
    dst = dst_buffer;
}