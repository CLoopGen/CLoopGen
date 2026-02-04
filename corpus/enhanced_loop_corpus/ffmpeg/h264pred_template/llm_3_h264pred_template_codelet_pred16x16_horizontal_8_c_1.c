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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    const uint32_t a1 = ((src[-1 + i * stride]) * 16843009U);
    const uint32_t a2 = ((src[-1 + (i+1) * stride]) * 16843009U);
    uint8_t *base1 = src + i * stride;
    uint8_t *base2 = src + (i+1) * stride;

    ((av_alias32*)(base1 + 0 * sizeof(uint32_t)))->u32 = a1;
    ((av_alias32*)(base1 + 1 * sizeof(uint32_t)))->u32 = a1;
    ((av_alias32*)(base1 + 2 * sizeof(uint32_t)))->u32 = a1;
    ((av_alias32*)(base1 + 3 * sizeof(uint32_t)))->u32 = a1;

    ((av_alias32*)(base2 + 0 * sizeof(uint32_t)))->u32 = a2;
    ((av_alias32*)(base2 + 1 * sizeof(uint32_t)))->u32 = a2;
    ((av_alias32*)(base2 + 2 * sizeof(uint32_t)))->u32 = a2;
    ((av_alias32*)(base2 + 3 * sizeof(uint32_t)))->u32 = a2;
}
}
