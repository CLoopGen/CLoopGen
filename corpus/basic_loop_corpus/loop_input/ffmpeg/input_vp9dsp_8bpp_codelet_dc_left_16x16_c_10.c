#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
uint8_t *dst;
uint32_t dc;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB
static uint8_t *buffer;

void init_vars() {
    // Allocate large buffer to ensure loop takes significant time (~0.01 sec)
    buffer = aligned_alloc(32, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize variables
    stride = 16; // Each row advances by 16 bytes (4x uint32_t per row)
    dst = buffer;
    dc = 0xDEADBEEF; // Sample value to store
    y = 0;

    // Ensure we can write at least 16 rows of 16 bytes without going out of bounds
    if (DATA_SIZE < (16 * stride)) {
        fprintf(stderr, "Buffer too small\n");
        exit(1);
    }
}