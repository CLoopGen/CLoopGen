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
extern int i;
extern uint32_t dc0splat;
extern uint32_t dc1splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < 6; i++) {
    uint8_t *base = src + i * stride;
    uint32_t *row = (uint32_t *)base;
    av_alias32 *a0 = (av_alias32 *)(row + 0);
    av_alias32 *a1 = (av_alias32 *)(row + 1);
    a0->u32 = dc0splat ^ 0x12345678U;
    a1->u32 = dc1splat ^ 0x87654321U;
    a0->u32 += (a1->u32 >> 16) * 3;
    a1->u32 += (a0->u32 & 0xFFFF) + 1;
}
}
