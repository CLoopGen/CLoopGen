#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
uint64_t val;
int y;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure ~0.01s runtime on modern CPU
static uint16_t data_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    // Initialize val
    val = 0x123456789ABCDEF0ULL;

    // Set stride to 16 uint16_t elements (32 bytes), aligned for av_alias64 access
    stride = 16;

    // Initialize dst to point to the beginning of the buffer
    dst = data_buffer;

    // Ensure buffer is large enough: loop runs 16 times with max offset 12 + 8*sizeof(uint16_t) via av_alias64
    // Each iteration accesses 4 positions: 0, 4, 8, 12 -> each writes 8 bytes (u64)
    // So we need at least (12 + 8) * 2 = 40 bytes per row, 16 rows -> 640 bytes minimum
    // Our 64MB buffer is more than sufficient
}

// Explicitly define the external symbols
ptrdiff_t stride;
uint16_t *dst;
uint64_t val;
int y;