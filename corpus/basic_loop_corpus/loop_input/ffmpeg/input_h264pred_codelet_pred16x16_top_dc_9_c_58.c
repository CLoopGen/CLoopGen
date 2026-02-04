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
    data_size = 1 << 20; // 1MB of data (2^20 bytes)
    src_base = aligned_alloc(64, data_size);
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        src_base[idx] = 0;
    }

    dcsplat = 0x123456789ABCDEF0ULL;

    effective_stride = 32; // 32 bytes per row = 16 uint16_t elements
    stride = effective_stride / sizeof(uint16_t);

    src = src_base;

    // Ensure loop runs exactly 16 times without overrunning buffer:
    // We write 16 rows, each requiring 16 elements (offsets 0,4,8,12 -> 16 max)
    // So total needed: 16 * stride >= 16 * 16 = 256 elements minimum
    if (data_size < 16 * effective_stride) {
        fprintf(stderr, "Buffer too small\n");
        exit(1);
    }
}