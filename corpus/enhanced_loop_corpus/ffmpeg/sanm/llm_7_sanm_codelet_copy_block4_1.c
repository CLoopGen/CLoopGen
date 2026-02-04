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
    for (i = 0; i < h; i++) {
        uint32_t val1 = (((const union unaligned_32 *)(src + 0))->l);
        uint32_t val2 = (i > 0) ? (((const union unaligned_32 *)(src - srcStride))->l) : val1;
        ((((union unaligned_32 *)(dst))->l) = val1 ^ val2);
        dst += dstStride;
        src += srcStride;
    }
}
