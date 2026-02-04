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
for (y = 0; y < 32; y++) {
    ((av_alias32 *)(dst + 0 * stride))->u32 = val;
    ((av_alias32 *)(dst + 1 * stride))->u32 = val;
    ((av_alias32 *)(dst + 2 * stride))->u32 = val;
    ((av_alias32 *)(dst + 3 * stride))->u32 = val;
    ((av_alias32 *)(dst + 4 * stride))->u32 = val;
    ((av_alias32 *)(dst + 5 * stride))->u32 = val;
    ((av_alias32 *)(dst + 6 * stride))->u32 = val;
    ((av_alias32 *)(dst + 7 * stride))->u32 = val;
    dst += 8 * stride;
}
}
