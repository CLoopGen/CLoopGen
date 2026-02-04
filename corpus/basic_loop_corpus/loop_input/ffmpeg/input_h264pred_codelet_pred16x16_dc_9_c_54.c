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
ptrdiff_t effective_stride;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    effective_stride = 16; // each iteration writes 16 bytes (8 uint16_t)
    stride = effective_stride / sizeof(uint16_t); // stride in units of uint16_t

    src_base = (uint16_t*)aligned_alloc(64, data_size);
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_base;
    dcsplat = 0x0F0F0F0F0F0F0F0FULL;

    // Ensure we don't exceed bounds: 16 iterations * stride must leave room for 16-byte write at last step
    // Each write accesses up to +15 bytes from current src, so we need at least 16*stride + 16 bytes
    size_t required_size = (16 * effective_stride) + 16;
    if (required_size > data_size) {
        fprintf(stderr, "Buffer too small\n");
        exit(1);
    }
}

__attribute__((destructor))
static void cleanup() {
    if (src_base) {
        free(src_base);
    }
}