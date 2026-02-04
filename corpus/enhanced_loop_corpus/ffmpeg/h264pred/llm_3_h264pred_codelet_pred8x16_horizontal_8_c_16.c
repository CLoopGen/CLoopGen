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
    const ptrdiff_t index = (i * stride) & 15;
    const uint32_t a = ((src[index]) * 16843009U);
    (((av_alias32 *)(((uint32_t *)(src + index)) + 0))->u32 = (a));
    (((av_alias32 *)(((uint32_t *)(src + index)) + 1))->u32 = (a));
}
}
