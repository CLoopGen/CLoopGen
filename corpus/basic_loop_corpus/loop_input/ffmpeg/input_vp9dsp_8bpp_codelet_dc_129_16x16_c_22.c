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
uint32_t val;
int y;

static uint8_t *buffer;

void init_vars() {
    // Allocate 64MB of buffer to ensure loop takes measurable time (~0.01 sec on modern CPU)
    // Each iteration writes 16 bytes and strides by 'stride', 16 iterations => need at least 16*stride space
    // Set stride to 64 (cache-line aligned) and allocate enough for 16 rows
    stride = 64;  // Ensure alignment and avoid false sharing
    size_t total_size = 16 * stride;  // 16 rows, each with 'stride' spacing
    buffer = (uint8_t*)aligned_alloc(64, total_size);
    if (!buffer) {
        exit(1);
    }
    dst = buffer;
    val = 0xdeadbeef;  // Arbitrary test value
    y = 0;
}