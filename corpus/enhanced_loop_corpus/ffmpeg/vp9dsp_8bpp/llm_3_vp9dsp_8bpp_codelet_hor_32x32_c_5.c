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
for (y = 0; y < 32; y += 2) {
    uint32_t p4_0 = ((left[31 - y]) * 16843009U);
    uint32_t p4_1 = ((left[31 - (y + 1)]) * 16843009U);
    av_alias32 *dst0 = (av_alias32 *)(dst);
    av_alias32 *dst1 = (av_alias32 *)(dst + stride);
    for (int x = 0; x < 8; x++) {
        dst0[x].u32 = p4_0;
        dst1[x].u32 = p4_1;
    }
    dst += 2 * stride;
}
}
