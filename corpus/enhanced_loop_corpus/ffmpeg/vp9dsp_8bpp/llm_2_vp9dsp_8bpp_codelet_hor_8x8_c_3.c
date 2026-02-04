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
for (y = 0; y < 8; y++) {
    uint32_t p4 = ((left[y]) * 16843009U);  // Changed access from reverse (7-y) to forward consecutive
    (((av_alias32 *)(dst + 0))->u32 = (p4));
    (((av_alias32 *)(dst + 4))->u32 = (p4));
    dst += stride;
}
}
