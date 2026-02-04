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
for (i = 0; i < 32; i += 2) {
    uint32_t val = ((1 << 7) * 16843009U);
    (((av_alias32 *)(src + 0))->u32 = val);
    (((av_alias32 *)(src + 4))->u32 = val);
    (((av_alias32 *)(src + 8))->u32 = val);
    (((av_alias32 *)(src + 12))->u32 = val);
    src += stride;
    (((av_alias32 *)(src + 0))->u32 = val);
    (((av_alias32 *)(src + 4))->u32 = val);
    (((av_alias32 *)(src + 8))->u32 = val);
    (((av_alias32 *)(src + 12))->u32 = val);
    src += stride;
}
}
