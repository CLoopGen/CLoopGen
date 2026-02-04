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
extern uint64_t dc2splat;
extern uint64_t dc3splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < 8; i++) {
    uint16_t *base = src + i * stride;
    uint64_t val1 = dc2splat ^ 0x0F0F0F0F0F0F0F0FULL;
    uint64_t val2 = dc3splat ^ 0xFFFF0000FFFF0000ULL;
    (((av_alias64 *)(((uint64_t *)base) + 0))->u64 = (val1));
    (((av_alias64 *)(((uint64_t *)base) + 1))->u64 = (val2));
    val1 ^= 0xAAAAAAAAAAAAAAAALL;
    val2 ^= 0x5555555555555555ULL;
    (((av_alias64 *)(((uint64_t *)base) + 2))->u64 = (val1));
    (((av_alias64 *)(((uint64_t *)base) + 3))->u64 = (val2));
}
}
