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
    // Variant 2: Strided access with fixed offset accumulation (unroll and access vertically)
    uint8_t *base = src;
    ptrdiff_t step = stride;

    for (i = 0; i < 4; i++) {
        uint8_t *p = base + i * step;
        av_alias32 *a0 = (av_alias32*)p;
        av_alias32 *a1 = (av_alias32*)(p + sizeof(uint32_t));
        a0->u32 = dc0splat;
        a1->u32 = dc1splat;
    }
}
