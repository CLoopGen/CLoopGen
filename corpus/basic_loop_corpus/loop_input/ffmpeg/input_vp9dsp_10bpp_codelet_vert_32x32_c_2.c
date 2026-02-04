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

ptrdiff_t stride = 32;
uint16_t *dst;
uint64_t p4a = 0x0102030405060708ULL;
uint64_t p4b = 0x090A0B0C0D0E0F10ULL;
uint64_t p4c = 0x1112131415161718ULL;
uint64_t p4d = 0x191A1B1C1D1E1F20ULL;
uint64_t p4e = 0x2122232425262728ULL;
uint64_t p4f = 0x292A2B2C2D2E2F30ULL;
uint64_t p4g = 0x3132333435363738ULL;
uint64_t p4h = 0x393A3B3C3D3E3F40ULL;
int y;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024;
    dst = aligned_alloc(64, total_size);
    if (!dst) {
        exit(1);
    }
}