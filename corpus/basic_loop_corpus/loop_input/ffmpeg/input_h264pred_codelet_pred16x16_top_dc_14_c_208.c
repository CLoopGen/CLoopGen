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
size_t total_size = 64 * 1024 * 1024; // 64 MB of data

void init_vars() {
    stride = 16; // in units of uint16_t, so 32 bytes per row
    dcsplat = 0x0123456789ABCDEFULL;

    src_base = (uint16_t *)aligned_alloc(64, total_size);
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Ensure we can access up to src + 12 + 16*stride over 16 iterations without overflow
    // Maximum index: 16 iterations * stride + 12 = 16*16 + 12 = 268 uint16_t elements per column?
    // But we are stepping by stride each time, and writing 4x64-bit = 32 bytes per row
    // So we need at least 16 rows, each with 16+12? Actually: we write at offsets 0,4,8,12 -> 13th element
    // So per row: need 13 elements -> 13*2 = 26 bytes, but aligned to 32 bytes.
    // Total rows: 16 -> 16 * stride (in uint16_t) = 16 * 16 = 256 uint16_t = 512 bytes

    // However, our allocation is large enough (64MB), so just initialize base pointer
    src = src_base;
}

void cleanup() {
    if (src_base) {
        free(src_base);
    }
}