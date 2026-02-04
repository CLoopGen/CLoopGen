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
uint64_t dc2splat;
uint64_t dc3splat;
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (adjustable for timing)
    src = aligned_alloc(64, data_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = 16; // Ensures alignment and safe access for vectorized stores
    dc2splat = 0x0102030405060708ULL;
    dc3splat = 0x090A0B0C0D0E0F10ULL;
    i = 0;

    // Ensure initialization covers required range: i from 4 to 7 => index up to 7*stride + some offset
    // Each iteration writes two uint64_t (16 bytes), so we need at least 8 * stride + 16 bytes per row
    // Zero-initialize allocated memory to avoid undefined behavior
    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        src[idx] = 0;
    }
}