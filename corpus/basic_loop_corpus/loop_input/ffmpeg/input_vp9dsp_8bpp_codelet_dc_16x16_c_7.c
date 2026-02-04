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

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB to target ~0.01 sec runtime
static uint8_t *buffer;

void init_vars() {
    // Allocate large buffer to ensure meaningful runtime
    buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize variables
    stride = 16; // Each row advances by 16 bytes (4x uint32_t)
    dst = buffer;
    dc = 0xdeadbeefU; // Arbitrary value for dc
    y = 0;

    // Ensure we have enough space: 16 rows * stride must fit in buffer
    if (16 * stride > DATA_SIZE) {
        fprintf(stderr, "Buffer too small\n");
        exit(1);
    }
}