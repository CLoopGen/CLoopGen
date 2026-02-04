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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating offset pattern (micro-tiled access)
    uint8_t *d = dst;
    ptrdiff_t double_stride = stride * 2;
    for (y = 0; y < 8; y += 2) {
        (((av_alias32 *)(d + 0))->u32 = dc);
        (((av_alias32 *)(d + 4))->u32 = dc);
        d += stride;
        if (y + 1 < 8) {
            (((av_alias32 *)(d + 0))->u32 = dc);
            (((av_alias32 *)(d + 4))->u32 = dc);
            d += stride;
        }
    }
}
