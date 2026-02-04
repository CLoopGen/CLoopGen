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

void init_vars() {
    // Allocate 64MB of data to ensure loop runtime around 0.01 seconds
    // Ensure sufficient padding for src[-1] access at the beginning
    const size_t buffer_size = 64 * 1024 * 1024;
    uint8_t *buffer = (uint8_t *)aligned_alloc(32, buffer_size + 8);
    if (!buffer) exit(1);

    // Initialize buffer with non-zero values for realistic processing
    for (size_t idx = 0; idx < buffer_size + 8; idx++) {
        buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    // Set src to point after 4-byte prefix so that src[-1] is valid
    src = buffer + 4;

    // Set stride to a reasonable value (e.g., width of a row in byte image-like layout)
    // Using 1024 to simulate moderately wide rows, ensuring 8*stride stays within bounds
    stride = 1024;

    // Verify that all accesses in loop are within bounds:
    // Maximum index: src + 7 * stride + sizeof(uint32_t)*2 - 1
    // Must ensure: 7*stride + 7 < buffer_size
    // With stride=1024 and buffer_size=~64MB, this is safe
}