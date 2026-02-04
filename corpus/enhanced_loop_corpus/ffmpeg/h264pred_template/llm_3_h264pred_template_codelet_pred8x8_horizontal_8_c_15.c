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
for (i = 0; i < 8; i++) {
    const ptrdiff_t index = (i * stride);
    const uint32_t a = ((src[index - 1]) * 16843009U);
    uint8_t *base = src + index;
    for (int j = 0; j < 2; j++) {
        (((av_alias32 *)(((uint32_t *)(base)) + j))->u32 = (a));
    }
}
}
