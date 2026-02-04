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
for (i = 0; i < 16; i += 2) {
    uint8_t *row1 = src + i * stride;
    uint8_t *row2 = src + (i + 1) * stride;
    ((av_alias32*)(void*)row1)->u32 = dc0splat;
    ((av_alias32*)(void*)(row1 + 4))->u32 = dc1splat;
    ((av_alias32*)(void*)row2)->u32 = dc0splat;
    ((av_alias32*)(void*)(row2 + 4))->u32 = dc1splat;
}
}
