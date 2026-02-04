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
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    const int index = (i * 4) * stride;
    const uint64_t a = ((src[index] + src[index + stride]) * 281479271743489ULL) >> 1;
    (((av_alias64 *)(((uint64_t *)(src + index)) + 0))->u64 = (a));
    (((av_alias64 *)(((uint64_t *)(src + index)) + 1))->u64 = (a));
    (((av_alias64 *)(((uint64_t *)(src + index)) + 2))->u64 = (a));
    (((av_alias64 *)(((uint64_t *)(src + index)) + 3))->u64 = (a));
}
}
