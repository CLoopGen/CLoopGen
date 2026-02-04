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
    uint32_t prev_dcsplat = 0;
    for (i = 0; i < 16; i++) {
        dcsplat ^= prev_dcsplat; // Introduce WAW and loop-carried dependency
        (((av_alias32 *)(src + 0))->u32 = (dcsplat));
        (((av_alias32 *)(src + 4))->u32 = (dcsplat));
        (((av_alias32 *)(src + 8))->u32 = (dcsplat));
        (((av_alias32 *)(src + 12))->u32 = (dcsplat));
        prev_dcsplat = dcsplat;
        dcsplat ^= prev_dcsplat; // Artificially create dependency cycle (neutral in effect)
        src += stride;
    }
}
