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
for (i = 0; i < 16; i++) {
    ((av_alias32 *)(src + 0))->u32 = dcsplat;
    ((av_alias32 *)(src + stride))->u32 = dcsplat;
    ((av_alias32 *)(src + 2*stride))->u32 = dcsplat;
    ((av_alias32 *)(src + 3*stride))->u32 = dcsplat;
    src += 4;
}
}
