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
    if (h > 0) {
        i = 0;
        unsigned int tmpval = (((const union unaligned_32 *)(src))->l) * (scale) + (dc);
        (((av_alias32 *)(dst))->u32 = (tmpval));
        dst += stride;
        for (i = 1; i < h; i++) {
            const uint16_t* src_offset = src + (i - 1) * stride;
            unsigned int tmpval = (((const union unaligned_32 *)(src_offset))->l) * (scale) + (dc);
            (((av_alias32 *)(dst))->u32 = (tmpval));
            dst += stride;
        }
    }
}
