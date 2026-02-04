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
for (i = 0; i < 8; i++) {
    uint8_t *s = src;
    (((av_alias32 *)(s + 0))->u32 = dcsplat);
    (((av_alias32 *)(s + 2))->u32 = dcsplat);
    (((av_alias32 *)(s + 4))->u32 = dcsplat);
    (((av_alias32 *)(s + 6))->u32 = dcsplat);
    (((av_alias32 *)(s + 8))->u32 = dcsplat);
    (((av_alias32 *)(s + 10))->u32 = dcsplat);
    (((av_alias32 *)(s + 12))->u32 = dcsplat);
    (((av_alias32 *)(s + 14))->u32 = dcsplat);
    src += stride;
}
}
