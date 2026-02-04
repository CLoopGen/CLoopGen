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
    // Variant 2: Strided memory access with reversed iteration and stride scaling
    uint8_t *base = src;
    ptrdiff_t effective_stride = stride * 4; // Larger stride jump per iteration
    for (i = 15; i >= 0; i--) {
        uint8_t *row = base + i * effective_stride;
        ((av_alias32 *)(row + 0))->u32 = dcsplat;
        ((av_alias32 *)(row + 4))->u32 = dcsplat;
        ((av_alias32 *)(row + 8))->u32 = dcsplat;
        ((av_alias32 *)(row + 12))->u32 = dcsplat;
    }
}
