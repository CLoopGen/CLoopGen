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
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
        ((((union unaligned_16 *)(dst + dstStride))->l) = ((((const union unaligned_16 *)(src + srcStride))->l)));
    } else {
        ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
    }
    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
