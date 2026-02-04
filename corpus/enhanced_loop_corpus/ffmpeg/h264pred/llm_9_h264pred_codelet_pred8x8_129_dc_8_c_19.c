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
extern  uint32_t a;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint8_t *base = src + i * stride;
        ((av_alias32 *)(void*)(base + 0))->u32 = a;
        ((av_alias32 *)(void*)(base + 4))->u32 = a;
        ((av_alias32 *)(void*)(base + 8))->u32 = a;
        ((av_alias32 *)(void*)(base + 12))->u32 = a;
        ((av_alias32 *)(void*)(base + 16))->u32 = a;
        ((av_alias32 *)(void*)(base + 20))->u32 = a;
        ((av_alias32 *)(void*)(base + 24))->u32 = a;
        ((av_alias32 *)(void*)(base + 28))->u32 = a;
    }
}
