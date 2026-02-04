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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    uint8_t *row = dst;
    ((av_alias32 *)(row + 0))->u32 = dc;
    ((av_alias32 *)(row + 16))->u32 = dc;
    ((av_alias32 *)(row + 32))->u32 = dc;
    ((av_alias32 *)(row + 48))->u32 = dc;
    dst += stride;
}
}
