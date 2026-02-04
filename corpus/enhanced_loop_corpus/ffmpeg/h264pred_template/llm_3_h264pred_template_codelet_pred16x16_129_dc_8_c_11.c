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
    // Variant 2: Strided access with reversed write order in each iteration
    for (i = 0; i < 16; i++) {
        uint8_t *row = src + i * stride;
        (((av_alias32 *)(row + 12))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
        (((av_alias32 *)(row + 8))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
        (((av_alias32 *)(row + 4))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
        (((av_alias32 *)(row + 0))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
    }
}
