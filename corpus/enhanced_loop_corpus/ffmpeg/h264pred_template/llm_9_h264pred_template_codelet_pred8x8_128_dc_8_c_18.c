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
extern  uint32_t a;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint32_t *base = (uint32_t *)(src + i * stride);
        av_alias32 *p0 = (av_alias32 *)(base + 0);
        av_alias32 *p1 = (av_alias32 *)(base + 1);
        av_alias32 *p2 = (av_alias32 *)(base + 2);
        av_alias32 *p3 = (av_alias32 *)(base + 3);
        p0->u32 = a;
        p1->u32 = a;
        p2->u32 = a;
        p3->u32 = a;
    }
}
