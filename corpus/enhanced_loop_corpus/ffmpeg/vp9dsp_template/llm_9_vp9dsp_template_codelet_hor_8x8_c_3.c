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
extern  uint8_t *left;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    uint32_t p1 = (left[7 - y] * 8421505U);     // ~1/3 of original multiplier
    uint32_t p2 = (left[6 - y] * 16843009U);   // Additional access with wrap considerations
    uint32_t combined = (p1 + p2) ^ (p1 << 8);
    (((av_alias32 *)(dst + 0))->u32 = (combined));
    if (y < 3) {
        (((av_alias32 *)(dst + 4))->u32 = ((left[5 - y] * 16843009U)));
    } else {
        (((av_alias32 *)(dst + 4))->u32 = 0);
    }
    dst += stride;
}
}
