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
extern uint32_t dc4splat;
extern uint32_t dc5splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 8; i < 12; i++) {
    uint8_t *row = src + i * stride;
    uint32_t *row32 = (uint32_t *)row;
    av_alias32 *a0 = (av_alias32 *)(row32 + 0);
    av_alias32 *a1 = (av_alias32 *)(row32 + 1);
    a0->u32 = dc4splat ^ 0x12345678u;
    a1->u32 = dc5splat ^ 0x87654321u;
    a0->u32 += 0x00000001u;
    a1->u32 += 0x00000001u;
}
}
