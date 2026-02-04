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
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled inner loop over 8 elements
    uint8_t *d = dst;
    for (int y = 0; y < 32; y++) {
        av_alias32 *p = (av_alias32 *)d;
        p[0].u32 = val;
        p[1].u32 = val;
        p[2].u32 = val;
        p[3].u32 = val;
        p[4].u32 = val;
        p[5].u32 = val;
        p[6].u32 = val;
        p[7].u32 = val;
        d += stride;
    }
}
