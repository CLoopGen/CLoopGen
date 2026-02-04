#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
uint8_t *src3;
uint8_t *src4;
int dst_stride;
int src_stride1;
int src_stride2;
int src_stride3;
int src_stride4;
int h;
int i;

void init_vars() {
    const int element_size = 8; // Each iteration processes 8 bytes (two 32-bit loads/stores)
    const size_t total_data_size = 64 * 1024 * 1024; // Aim for ~64MB to target 0.01s runtime
    const int num_elements = total_data_size / element_size;

    h = num_elements;

    // Ensure strides are at least 8 bytes per element to avoid overlap
    dst_stride = 8;
    src_stride1 = 8;
    src_stride2 = 8;
    src_stride3 = 8;
    src_stride4 = 8;

    // Allocate buffers with padding to prevent out-of-bounds access
    // Each row accesses up to +7 bytes (4 + 4-byte load), so we need at least (h * stride + 7) bytes
    size_t dst_size = h * dst_stride + 8;
    size_t src_size = h * 8 + 8; // Each source needs space for two 32-bit reads per iteration

    dst = aligned_alloc(16, dst_size);
    src1 = aligned_alloc(16, src_size);
    src2 = aligned_alloc(16, src_size);
    src3 = aligned_alloc(16, src_size);
    src4 = aligned_alloc(16, src_size);

    // Initialize src buffers with non-zero data to ensure meaningful computation
    for (int j = 0; j < h; j++) {
        uint32_t val1 = (uint32_t)(0x9E3779B1 * j);
        uint32_t val2 = (uint32_t)(0xABC98765 * j);
        uint32_t val3 = (uint32_t)(0x12345678 * j);
        uint32_t val4 = (uint32_t)(0xDEADBEEF * j);

        // First 32-bit value
        ((uint32_t*)&src1[j * src_stride1])[0] = val1;
        ((uint32_t*)&src2[j * src_stride2])[0] = val2;
        ((uint32_t*)&src3[j * src_stride3])[0] = val3;
        ((uint32_t*)&src4[j * src_stride4])[0] = val4;

        // Second 32-bit value (+4 offset)
        ((uint32_t*)&src1[j * src_stride1 + 4])[0] = val1 ^ 0x55555555;
        ((uint32_t*)&src2[j * src_stride2 + 4])[0] = val2 ^ 0x55555555;
        ((uint32_t*)&src3[j * src_stride3 + 4])[0] = val3 ^ 0x55555555;
        ((uint32_t*)&src4[j * src_stride4 + 4])[0] = val4 ^ 0x55555555;
    }

    // Zero-initialize destination
    for (int j = 0; j < h; j++) {
        ((uint32_t*)&dst[j * dst_stride])[0] = 0;
        ((uint32_t*)&dst[j * dst_stride + 4])[0] = 0;
    }
}