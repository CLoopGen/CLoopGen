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
    // Variant 1: Consecutive memory access by reorganizing data layout access
    uint8_t *base = src;
    for (i = 0; i < 4; i++) {
        uint32_t *row = (uint32_t *)(base + i * stride);
        ((av_alias32*)&row[0])->u32 = dc0splat;
        ((av_alias32*)&row[1])->u32 = dc1splat;
    }
}
