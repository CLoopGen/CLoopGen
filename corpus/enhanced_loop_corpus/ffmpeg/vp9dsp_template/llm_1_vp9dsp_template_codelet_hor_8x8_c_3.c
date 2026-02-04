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
    for (int sub_y = 0; sub_y < 2; sub_y++) {
        int index = 7 - (y * 2 + sub_y);
        uint32_t p4 = ((left[index]) * 16843009U);
        (((av_alias32 *)(dst + 0))->u32 = (p4));
        (((av_alias32 *)(dst + 4))->u32 = (p4));
        dst += stride;
    }
}
}
