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
extern uint32_t dc0splat;
extern uint32_t dc1splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unrolled and restructured for sequential writes)
    uint32_t *base0 = (uint32_t *)(src + 4 * stride);
    uint32_t *base1 = (uint32_t *)(src + 5 * stride);
    uint32_t *base2 = (uint32_t *)(src + 6 * stride);
    uint32_t *base3 = (uint32_t *)(src + 7 * stride);

    ((av_alias32*)(base0 + 0))->u32 = dc0splat;
    ((av_alias32*)(base0 + 1))->u32 = dc1splat;

    ((av_alias32*)(base1 + 0))->u32 = dc0splat;
    ((av_alias32*)(base1 + 1))->u32 = dc1splat;

    ((av_alias32*)(base2 + 0))->u32 = dc0splat;
    ((av_alias32*)(base2 + 1))->u32 = dc1splat;

    ((av_alias32*)(base3 + 0))->u32 = dc0splat;
    ((av_alias32*)(base3 + 1))->u32 = dc1splat;
}
