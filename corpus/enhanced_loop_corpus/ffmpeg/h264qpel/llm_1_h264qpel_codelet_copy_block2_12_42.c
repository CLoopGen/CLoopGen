#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int block = 0; block < h / 4; block++) {
        for (int step = 0; step < 4; step++) {
            i = block * 4 + step;
            ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
            dst += dstStride;
            src += srcStride;
        }
    }
    for (i = (h / 4) * 4; i < h; i++) {
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        dst += dstStride;
        src += srcStride;
    }
}
