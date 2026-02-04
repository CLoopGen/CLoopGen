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
uint16_t *dst;
uint64_t dc = 0x0101010101010101ULL;
int y;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data to ensure ~0.01s runtime
    dst = aligned_alloc(64, total_size);
    if (!dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size / sizeof(uint16_t); i++) {
        dst[i] = 0;
    }

    dc = 0x0101010101010101ULL;
    stride = 16;
}