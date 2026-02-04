#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
int i;
uint64_t a;
uint16_t *src;

#define DATA_SIZE (128 << 20) // 128 MB

static uint16_t data_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    // Initialize scalar variables
    stride = 16; // stride in units of uint16_t, ensures sufficient spacing
    a = 0x123456789ABCDEF0ULL;

    // Initialize src to point to the middle of the buffer to allow indexing with stride * 8 safely
    // Ensure that src + 8 * stride stays within bounds
    size_t min_offset = 8 * stride;
    if (min_offset < DATA_SIZE / sizeof(uint16_t)) {
        src = data_buffer + (DATA_SIZE / sizeof(uint16_t)) / 2;
    } else {
        src = data_buffer;
    }

    // Explicitly zero-initialize the touched region to avoid garbage in tests
    memset(src, 0, 8 * stride * sizeof(uint16_t));
}