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
        uint32_t temp1, temp2;
        // Introduce temporary variables to modify RAW/WAW dependencies
        // and reorder computations to change data flow

        temp1 = (((const union unaligned_32 *)(src + 0))->l);
        temp2 = (((const union unaligned_32 *)(src + 2))->l);

        temp1 = temp1 * scale + dc;
        temp2 = temp2 * scale + dc;

        (((av_alias32 *)(dst + 0))->u32) = temp1;
        (((av_alias32 *)(dst + 2))->u32) = temp2;

        if (scale)
            src += stride;
        dst += stride;
    }
}
