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
for (y = 0; y < 64; y++) {
    (((av_alias64 *)(dst + 0))->u64 = (val));
    (((av_alias64 *)(dst + 2))->u64 = (val));
    (((av_alias64 *)(dst + 4))->u64 = (val));
    (((av_alias64 *)(dst + 6))->u64 = (val));
    (((av_alias64 *)(dst + 8))->u64 = (val));
    (((av_alias64 *)(dst + 10))->u64 = (val));
    (((av_alias64 *)(dst + 12))->u64 = (val));
    (((av_alias64 *)(dst + 14))->u64 = (val));
    (((av_alias64 *)(dst + 16))->u64 = (val));
    (((av_alias64 *)(dst + 18))->u64 = (val));
    (((av_alias64 *)(dst + 20))->u64 = (val));
    (((av_alias64 *)(dst + 22))->u64 = (val));
    (((av_alias64 *)(dst + 24))->u64 = (val));
    (((av_alias64 *)(dst + 26))->u64 = (val));
    (((av_alias64 *)(dst + 28))->u64 = (val));
    (((av_alias64 *)(dst + 30))->u64 = (val));
    dst += stride;
}
}
