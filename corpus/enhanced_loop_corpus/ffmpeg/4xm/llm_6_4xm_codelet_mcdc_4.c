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
        unsigned int tmpval;
        uint16_t *local_src = src;
        uint16_t *local_dst = dst;

        tmpval = (((const union unaligned_32 *)(local_src))->l) * scale + dc;
        (((av_alias32 *)(local_dst))->u32 = tmpval);

        // Introduce artificial loop-carried dependency via dc update
        dc += ((tmpval >> 16) & 0xFFFF); // Feedback of high word into dc

        if (scale)
            src += stride;
        dst += stride;
    }
}
