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
        unsigned int tmpval1, tmpval2;
        uint16_t* current_src = src;
        uint16_t* current_dst = dst;

        // Eliminate loop-carried dependency on 'dst' by using local pointers
        // and delay update until end of iteration; reorder operations

        tmpval1 = (((const union unaligned_32 *)(current_src + 0))->l) * scale + dc;
        (((av_alias32 *)(current_dst + 2))->u32) = tmpval1;  // Swap order of stores

        tmpval2 = (((const union unaligned_32 *)(current_src + 2))->l) * scale + dc;
        (((av_alias32 *)(current_dst + 0))->u32) = tmpval2;  // Create WAR-like pattern locally

        // Maintain original side effects on src/dst only at the end
        if (scale)
            src += stride;
        dst += stride;
    }
}
