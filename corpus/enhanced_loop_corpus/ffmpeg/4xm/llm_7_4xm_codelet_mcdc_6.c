#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern uint16_t *dst;
extern  uint16_t *src;
extern int h;
extern int stride;
extern int scale;
extern unsigned int dc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    unsigned int accumulated_dc = dc;
    for (int j = 0; j < 4; j++) {
        unsigned int offset = j * 2;
        unsigned int tmpval = (((const union unaligned_32 *)(src + offset))->l) * scale + accumulated_dc;
        (((av_alias32 *)(dst + offset))->u32 = tmpval);
        accumulated_dc += (tmpval & 0xFFFF); // Introduce WAW and loop-carried dependency: dc update depends on prior write
    }

    if (scale)
        src += stride;
    dst += stride;
}
}
