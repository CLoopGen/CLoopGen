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

ptrdiff_t stride = 16; // Ensures 128-bit alignment and spacing
int i;
uint64_t dc0splat = 0x0102030405060708ULL;
uint64_t dc1splat = 0x090A0B0C0D0E0F10ULL;
uint16_t *src;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    const size_t num_elements = data_size / sizeof(uint16_t);
    src = aligned_alloc(32, data_size);
    if (!src) {
        exit(1);
    }
}