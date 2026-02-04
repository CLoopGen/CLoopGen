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
for (y = 0; y < 4; y++) {
    uint32_t val1 = val ^ 0xAAAAAAAA;
    uint32_t val2 = val ^ 0x55555555;
    (((av_alias32 *)(dst + 0))->u32 = (val1));
    (((av_alias32 *)(dst + 4))->u32 = (val2));
    (((av_alias32 *)(dst + stride))->u32 = (val1));
    (((av_alias32 *)(dst + stride + 4))->u32 = (val2));
    dst += 2 * stride;
}
}
