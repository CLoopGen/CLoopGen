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
        uint8_t *row = base_src + i * stride;
        av_alias32 *p = (av_alias32 *)row;
        p[0].u32 = ((1 << (8 - 1)) - 1) * 16843009U;
        p[1].u32 = ((1 << (8 - 1)) - 1) * 16843009U;
        p[2].u32 = ((1 << (8 - 1)) - 1) * 16843009U;
        p[3].u32 = ((1 << (8 - 1)) - 1) * 16843009U;
    }
}
