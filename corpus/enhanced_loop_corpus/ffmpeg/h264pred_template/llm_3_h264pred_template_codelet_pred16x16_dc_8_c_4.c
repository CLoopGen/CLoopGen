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
for (i = 0; i < 16; i += 4) {
    uint8_t *base0 = src + 0 * stride;
    uint8_t *base1 = src + 1 * stride;
    uint8_t *base2 = src + 2 * stride;
    uint8_t *base3 = src + 3 * stride;

    ((av_alias32 *)(base0 + 0))->u32 = dcsplat;
    ((av_alias32 *)(base0 + 4))->u32 = dcsplat;
    ((av_alias32 *)(base0 + 8))->u32 = dcsplat;
    ((av_alias32 *)(base0 + 12))->u32 = dcsplat;

    ((av_alias32 *)(base1 + 0))->u32 = dcsplat;
    ((av_alias32 *)(base1 + 4))->u32 = dcsplat;
    ((av_alias32 *)(base1 + 8))->u32 = dcsplat;
    ((av_alias32 *)(base1 + 12))->u32 = dcsplat;

    ((av_alias32 *)(base2 + 0))->u32 = dcsplat;
    ((av_alias32 *)(base2 + 4))->u32 = dcsplat;
    ((av_alias32 *)(base2 + 8))->u32 = dcsplat;
    ((av_alias32 *)(base2 + 12))->u32 = dcsplat;

    ((av_alias32 *)(base3 + 0))->u32 = dcsplat;
    ((av_alias32 *)(base3 + 4))->u32 = dcsplat;
    ((av_alias32 *)(base3 + 8))->u32 = dcsplat;
    ((av_alias32 *)(base3 + 12))->u32 = dcsplat;

    src += 4 * stride;
}
}
