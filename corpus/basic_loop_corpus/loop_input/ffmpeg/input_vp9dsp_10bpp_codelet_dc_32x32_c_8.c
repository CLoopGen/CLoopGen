#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
uint16_t *dst;
uint64_t dc;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of data
static uint16_t buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    // Initialize dc to a known value, e.g., all bits set
    dc = UINT64_C(0xFFFFFFFFFFFFFFFF);

    // Set stride to 32 uint16_t elements (64 bytes), which advances dst by 32*2 = 64 bytes per iteration
    // This ensures that each loop writes to a new cache line and avoids overlap
    stride = 32;

    // Initialize dst to point to the beginning of buffer
    dst = buffer;

    // Ensure that the total memory access in the loop does not exceed buffer bounds
    // Loop runs 32 times, each time accessing 8 consecutive 64-bit (8-byte) chunks starting from dst offset 0 to 28
    // Each chunk is 8 bytes -> covers 64 bytes per row
    // Total rows: 32, with stride of 64 bytes per row -> total span: 32 * stride = 2048 bytes
    // We have 128MB buffer, so we are well within bounds
}