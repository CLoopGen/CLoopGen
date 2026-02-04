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
extern int i;
extern uint64_t dc6splat;
extern uint64_t dc7splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 12; i < 16; i++) {
    uint16_t *base = src + i * stride;
    uint64_t val1 = dc6splat ^ 0x123456789ABCDEF0ULL;
    uint64_t val2 = dc7splat ^ 0xFEDCBA9876543210ULL;
    (((av_alias64 *)(((uint64_t *)base) + 0))->u64 = (val1));
    (((av_alias64 *)(((uint64_t *)base) + 1))->u64 = (val2));
    (((av_alias64 *)(((uint64_t *)base) + 2))->u64 = (val1 ^ val2));
    (((av_alias64 *)(((uint64_t *)base) + 3))->u64 = (val2 ^ val1));
}
}
