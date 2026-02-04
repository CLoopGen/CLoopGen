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
uint64_t dcsplat;

uint16_t *src_base;
size_t data_size;
ptrdiff_t src_stride_in_elements;

void init_vars() {
    data_size = 1 << 20; // 1MB of data
    src_stride_in_elements = 16; // Each iteration advances by 16 uint16_t elements
    stride = src_stride_in_elements;

    src_base = (uint16_t*)aligned_alloc(64, data_size);
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_base;

    dcsplat = 0x0F0F0F0F0F0F0F0FULL;

    // Ensure that over 16 iterations, we don't go out of bounds
    // Total accessed: 16 rows * stride per row <= allocated size in elements
    // We access +0, +4, +8, +12 in each row -> 4x av_alias64 writes per row
    // So we need at least 16 * (last offset + width) = 16 * (12 + 4) = 16 * 16 = 256 uint16_t
    size_t min_required_elements = 16 * src_stride_in_elements;
    if (min_required_elements * sizeof(uint16_t) > data_size) {
        fprintf(stderr, "Buffer too small\n");
        exit(1);
    }

    // Initialize the entire buffer to avoid undefined behavior
    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        src_base[idx] = 0;
    }
}