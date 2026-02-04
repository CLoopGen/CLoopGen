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
    // Variant 2: Strided memory access — write every 2nd 32-bit word, doubling the effective stride within row
    uint8_t *d = dst;
    for (int y = 0; y < 32; y++) {
        av_alias32 *p = (av_alias32 *)d;
        p[0].u32 = val;
        p[2].u32 = val;
        p[4].u32 = val;
        p[6].u32 = val;
        p[8].u32 = val;
        p[10].u32 = val;
        p[12].u32 = val;
        p[14].u32 = val;
        d += stride;
    }
}
