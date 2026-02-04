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
    const size_t total_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime
    src = aligned_alloc(64, total_size);
    if (!src) {
        exit(1);
    }

    stride = 1024 / sizeof(uint16_t); // 512 elements per row (1024 bytes)
    dc0splat = 0x0123456789ABCDEFULL;
    dc1splat = 0xFEDCBA9876543210ULL;
}

__attribute__((destructor))
static void cleanup() {
    free(src);
}