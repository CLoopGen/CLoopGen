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
for (i = 0; i < 8; i++) {
    uint32_t val1 = ((1 << 7) + 0) * 16843009U;
    uint32_t val2 = val1 ^ 0xFFFFFFFF;
    uint32_t val3 = (val1 >> 1) + (val1 << 31);
    uint32_t val4 = val2 ^ (val1 + 12345);

    (((av_alias32 *)(src + 0))->u32 = val1);
    (((av_alias32 *)(src + 4))->u32 = val2);
    (((av_alias32 *)(src + 8))->u32 = val3);
    (((av_alias32 *)(src + 12))->u32 = val4);
    src += stride;

    (((av_alias32 *)(src + 0))->u32 = val4);
    (((av_alias32 *)(src + 4))->u32 = val3);
    (((av_alias32 *)(src + 8))->u32 = val2);
    (((av_alias32 *)(src + 12))->u32 = val1);
    src += stride;
}
}
