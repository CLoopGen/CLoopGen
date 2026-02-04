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
    // Variant 1: Consecutive memory access (transpose the iteration to access consecutive 32-bit chunks)
    uint32_t *row0 = (uint32_t *)(src);
    uint32_t *row1 = (uint32_t *)(src + stride);
    uint32_t *row2 = (uint32_t *)(src + 2 * stride);
    uint32_t *row3 = (uint32_t *)(src + 3 * stride);

    ((av_alias32 *)(row0 + 0))->u32 = dc0splat;
    ((av_alias32 *)(row0 + 1))->u32 = dc1splat;
    ((av_alias32 *)(row1 + 0))->u32 = dc0splat;
    ((av_alias32 *)(row1 + 1))->u32 = dc1splat;
    ((av_alias32 *)(row2 + 0))->u32 = dc0splat;
    ((av_alias32 *)(row2 + 1))->u32 = dc1splat;
    ((av_alias32 *)(row3 + 0))->u32 = dc0splat;
    ((av_alias32 *)(row3 + 1))->u32 = dc1splat;
}
