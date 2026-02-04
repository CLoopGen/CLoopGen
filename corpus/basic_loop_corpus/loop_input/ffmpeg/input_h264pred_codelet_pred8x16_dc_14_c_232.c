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
uint64_t dc0splat;
uint64_t dc1splat;
uint16_t *src;

void init_vars() {
    dc0splat = 0x0123456789ABCDEFULL;
    dc1splat = 0xFEDCBA9876543210ULL;
    stride = 8;
    int total_elements = 4 * stride + 2; 
    src = (uint16_t *)aligned_alloc(8, total_elements * sizeof(uint16_t));
    if (!src) {
        exit(1);
    }
    for (int idx = 0; idx < total_elements; idx++) {
        src[idx] = idx & 0xFFFF;
    }
}