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
extern uint32_t p4a;
extern uint32_t p4b;
extern uint32_t p4c;
extern uint32_t p4d;
extern uint32_t p4e;
extern uint32_t p4f;
extern uint32_t p4g;
extern uint32_t p4h;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using array-of-structures pattern with fixed offsets
    uint8_t *base = dst;
    ptrdiff_t offset = 0;
    for (y = 0; y < 32; y++) {
        ((av_alias32 *)(base + offset +  0))->u32 = p4a;
        ((av_alias32 *)(base + offset + 32))->u32 = p4b;
        ((av_alias32 *)(base + offset + 64))->u32 = p4c;
        ((av_alias32 *)(base + offset + 96))->u32 = p4d;
        ((av_alias32 *)(base + offset +128))->u32 = p4e;
        ((av_alias32 *)(base + offset +160))->u32 = p4f;
        ((av_alias32 *)(base + offset +192))->u32 = p4g;
        ((av_alias32 *)(base + offset +224))->u32 = p4h;
        offset += stride;
    }
}
