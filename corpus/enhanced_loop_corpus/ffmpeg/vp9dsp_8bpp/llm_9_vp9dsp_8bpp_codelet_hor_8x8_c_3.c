#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern uint8_t *dst;
extern  uint8_t *left;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    uint32_t p4_0 = ((left[3 - y]) * 16843009U);
    uint32_t p4_1 = ((left[7 - y]) * 16843009U);
    // Reduced trip count but unrolled to maintain memory operations, with mixed inputs
    (((av_alias32 *)(dst + 0))->u32 = (p4_0));
    (((av_alias32 *)(dst + 4))->u32 = (p4_1));
    (((av_alias32 *)(dst + stride + 0))->u32 = (p4_1));
    (((av_alias32 *)(dst + stride + 4))->u32 = (p4_0));
    dst += 2 * stride;
}
}
