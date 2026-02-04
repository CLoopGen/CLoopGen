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
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with sequential 32-bit writes
    uint8_t *base_src = src;
    for (i = 0; i < 16; i++) {
        av_alias32 *p = (av_alias32 *)(base_src + i * stride);
        p->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        p = (av_alias32 *)((uint8_t *)p + 4);
        p->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        p = (av_alias32 *)((uint8_t *)p + 4);
        p->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        p = (av_alias32 *)((uint8_t *)p + 4);
        p->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
    }
}
