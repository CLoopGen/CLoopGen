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
    for (int block = 0; block < h / 4; block++) {
        for (i = 0; i < 4; i++) {
            int idx = block * 4 + i;
            if (idx < h) {
                ((((union unaligned_32 *)(dst + idx * dstStride))->l) = 
                 ((((const union unaligned_32 *)(src + idx * srcStride))->l)));
            }
        }
    }
    // Handle remaining iterations
    for (i = (h / 4) * 4; i < h; i++) {
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        dst += dstStride;
        src += srcStride;
    }
}
