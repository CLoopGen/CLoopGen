#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
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
    ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
    ((((union unaligned_32 *)(dst + dstStride))->l) = ((((const union unaligned_32 *)(src + srcStride))->l)));
    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
