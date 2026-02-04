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

extern ptrdiff_t stride;
extern uint16_t *dst;
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    uint64_t v1 = val;
    uint64_t v2 = val ^ 0x123456789ABCDEF0;
    uint64_t v3 = val + 0xFEDCBA9876543210;
    uint64_t v4 = val - 1;

    ((av_alias64 *)(dst + 0))->u64 = v1;
    ((av_alias64 *)(dst + 4))->u64 = v2;
    ((av_alias64 *)(dst + 8))->u64 = v3;
    ((av_alias64 *)(dst + 12))->u64 = v4;
    ((av_alias64 *)(dst + 16))->u64 = v1;
    ((av_alias64 *)(dst + 20))->u64 = v2;
    ((av_alias64 *)(dst + 24))->u64 = v3;
    ((av_alias64 *)(dst + 28))->u64 = v4;

    for (int i = 0; i < 2; ++i) {
        v1 ^= v2 + v3 - v4;
        v2 = (v2 >> 1) | (v1 << 63);
        v3 ^= 0x55AA55AA55AA55AA;
        v4 = ~v4;
    }

    dst += stride;
}
}
