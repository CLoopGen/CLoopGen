#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        if (i % 2 == 0) {
            ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
        } else {
            ((uint8_t*)dst)[0] = ((const uint8_t*)src)[0];
            ((uint8_t*)dst)[1] = ((const uint8_t*)src)[1];
        }
        dst += dstStride;
        src += srcStride;
    }
}
