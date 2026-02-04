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
for (i = 0; i < 2; i++) {
    uint32_t *base = (uint32_t *)(src + i * stride);
    av_alias32 *a0 = (av_alias32 *)(base + 0);
    av_alias32 *a1 = (av_alias32 *)(base + 1);
    av_alias32 *a2 = (av_alias32 *)(base + 2);
    av_alias32 *a3 = (av_alias32 *)(base + 3);
    a0->u32 = dc0splat;
    a1->u32 = dc1splat;
    a2->u32 = dc0splat;
    a3->u32 = dc1splat;
}
}
