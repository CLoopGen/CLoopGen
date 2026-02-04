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



void loop() {
    for (i = 0; i < h; i++) {
        for (int j = 0; j < 4; j++) {
            unsigned int tmpval = (((const union unaligned_32 *)(src + 2*j))->l) * scale + dc;
            (((av_alias32 *)(dst + 2*j))->u32 = tmpval);
        }
        if (scale)
            src += stride;
        dst += stride;
    }
}
