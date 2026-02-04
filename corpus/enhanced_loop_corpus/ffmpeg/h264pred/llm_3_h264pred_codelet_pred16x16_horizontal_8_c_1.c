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
for (i = 0; i < 64; i += 4) {
    const uint32_t a = ((src[-1 + (i/4) * stride]) * 16843009U);
    uint32_t *dst = (uint32_t*)(src + (i/4) * stride);
    ((av_alias32*)(void*)&dst[0])->u32 = a;
    ((av_alias32*)(void*)&dst[1])->u32 = a;
    ((av_alias32*)(void*)&dst[2])->u32 = a;
    ((av_alias32*)(void*)&dst[3])->u32 = a;
}
}
