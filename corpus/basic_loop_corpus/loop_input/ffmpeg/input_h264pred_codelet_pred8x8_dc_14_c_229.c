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

ptrdiff_t stride = 16;
int i = 0;
uint64_t dc0splat = 0x0123456789ABCDEFULL;
uint64_t dc1splat = 0xFEDCBA9876543210ULL;
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    src = aligned_alloc(64, data_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}