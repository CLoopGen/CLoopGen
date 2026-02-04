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
for (i = 0; i < 64; i += 4) {
    uint8_t *base = src + i;
    ((av_alias32 *)(base))->u32 = dcsplat;
    ((av_alias32 *)(base + 1 * stride))->u32 = dcsplat;
    ((av_alias32 *)(base + 2 * stride))->u32 = dcsplat;
    ((av_alias32 *)(base + 3 * stride))->u32 = dcsplat;
}
src += 4 * stride; // Adjust src if used externally, maintaining original effect over 16 iterations
}
