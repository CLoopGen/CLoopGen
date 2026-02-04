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
    // Variant 2: Strided access with alternating offset pattern (non-unit stride in elements)
    uint8_t *base = dst;
    ptrdiff_t effective_stride = stride * 2; // Simulate wider striding across rows
    for (y = 0; y < 8; y += 2) {
        (((av_alias32 *)(base + 0))->u32 = (val));
        (((av_alias32 *)(base + 4))->u32 = (val));
        base += effective_stride;

        if (y + 1 < 8) {
            (((av_alias32 *)(base - stride))->u32 = (val));
            (((av_alias32 *)(base - stride + 4))->u32 = (val));
        }
    }
}
