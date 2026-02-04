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
int i;
uint8_t *src;
uint32_t dcsplat;

uint8_t *src_buffer;

void init_vars() {
    // Allocate 64MB of data to ensure loop takes significant time (~0.01 sec on modern CPU)
    size_t buffer_size = 64 * 1024 * 1024;
    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    if (!src_buffer) exit(1);

    // Initialize variables
    stride = 16;  // Advance by 16 bytes per iteration
    src = src_buffer;
    dcsplat = 0xDEADBEEF;  // Arbitrary pattern

    // Ensure we don't exceed bounds: 16 iterations * stride must leave room for 16-byte write
    // Each iteration writes 16 bytes starting at src + 0,4,8,12 -> total 16 bytes
    // So we require at least 16 * stride + 16 bytes in buffer
    size_t required_size = 16 * stride + 16;
    if (required_size > buffer_size) {
        // This should not happen with current settings
        free(src_buffer);
        exit(1);
    }
}