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
int i;
uint16_t *src;

#define DATA_SIZE (128 * 1024 * 1024)  // 128 MB of data
static uint16_t buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 16;  // Advance by 16 uint16_t elements per iteration (32 bytes)
    src = buffer;

    // Ensure that over the 16 iterations, we don't go out of bounds
    // Maximum offset: src + 12 + (16 * 15) = src + 252 bytes = 126 uint16_t elements
    // So we need at least 126 elements in the buffer -> our 128MB is more than sufficient
}

// Explicitly initialize all external symbols to satisfy linkage
__attribute__((constructor))
static void constructor_init() {
    init_vars();
}