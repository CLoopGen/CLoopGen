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
    // Variant 2: Strided access with reversed iteration order (backward striding through rows)
    for (i = 7; i >= 4; i--) {
        uint8_t *row = src + i * stride;
        uint32_t *row32 = (uint32_t *)row;

        ((av_alias32*)&row32[0])->u32 = dc0splat;
        ((av_alias32*)&row32[1])->u32 = dc1splat;
    }
}
