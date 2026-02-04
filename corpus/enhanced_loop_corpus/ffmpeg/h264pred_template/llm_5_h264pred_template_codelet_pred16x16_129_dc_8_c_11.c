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
for (i = 0; i < 16; i++) {
    if (i >= 8) {
        (((av_alias32 *)(src + 0))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
    } else {
        (((av_alias32 *)(src + 4))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
    }
    if (i != 5 && i != 13) {
        (((av_alias32 *)(src + 8))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
        (((av_alias32 *)(src + 12))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U)));
    }
    src += stride;
}
}
