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
extern uint32_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled writes
    uint8_t *base = src;
    for (i = 0; i < 16; i++) {
        uint8_t *row = base + i * stride;
        av_alias32 *a = (av_alias32 *)row;
        a[0].u32 = dcsplat;
        a[1].u32 = dcsplat;
        a[2].u32 = dcsplat;
        a[3].u32 = dcsplat;
    }
}
