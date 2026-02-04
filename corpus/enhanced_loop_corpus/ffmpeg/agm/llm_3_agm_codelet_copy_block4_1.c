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
    uint8_t *d1 = dst;
    uint8_t *s1 = src;
    uint8_t *d2 = dst + dstStride;
    uint8_t *s2 = src + srcStride;
    
    if (i < h) {
        ((((union unaligned_32 *)(d1))->l) = ((((const union unaligned_32 *)(s1))->l)));
    }
    if (i + 1 < h) {
        ((((union unaligned_32 *)(d2))->l) = ((((const union unaligned_32 *)(s2))->l)));
    }
    
    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
