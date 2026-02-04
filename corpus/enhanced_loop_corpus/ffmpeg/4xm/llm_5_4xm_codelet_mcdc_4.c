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
    unsigned int tmpval;
    if (i >= h / 2) {
        tmpval = (((const union unaligned_32 *)(src))->l) * (scale ? scale : 1) + dc;
    } else {
        tmpval = (((const union unaligned_32 *)(src))->l) + dc;
    }
    (((av_alias32 *)(dst))->u32 = tmpval);
    dst += stride;
    if (scale != 0)
        src += stride;
}
}
