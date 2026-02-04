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
uint64_t dc6splat;
uint64_t dc7splat;
uint16_t *src;

void init_vars() {
    stride = 16;
    dc6splat = 0x0123456789ABCDEFULL;
    dc7splat = 0xFEDCBA9876543210ULL;

    size_t data_size = 256 * 1024 * 1024; // 256 MB
    src = (uint16_t*)aligned_alloc(64, data_size);
    if (!src) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}