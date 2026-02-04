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
extern uint64_t dc4splat;
extern uint64_t dc5splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 8; i < 10; i++) {
    uint64_t temp_dc4 = dc4splat ^ 0x123456789ABCDEF0ULL;
    uint64_t temp_dc5 = dc5splat ^ 0xFEDCBA9876543210ULL;
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (temp_dc4));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (temp_dc5));
    temp_dc4 ^= 0x123456789ABCDEF0ULL;
    temp_dc5 ^= 0xFEDCBA9876543210ULL;
    (((av_alias64 *)(((uint64_t *)(src + (i * stride) + 1)) + 0))->u64 = (temp_dc4));
    (((av_alias64 *)(((uint64_t *)(src + (i * stride) + 1)) + 1))->u64 = (temp_dc5));
}
}
