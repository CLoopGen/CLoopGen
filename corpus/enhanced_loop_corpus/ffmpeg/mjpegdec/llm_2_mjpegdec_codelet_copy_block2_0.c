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
    // Variant 1: Consecutive memory access with unrolled loop (accessing two elements per iteration)
    int i;
    for (i = 0; i < h - 1; i += 2) {
        ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
        dst += dstStride;
        src += srcStride;
        ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
        dst += dstStride;
        src += srcStride;
    }
    // Handle remaining element if h is odd
    if (i < h) {
        ((((union unaligned_16 *)(dst))->l) = ((((const union unaligned_16 *)(src))->l)));
        dst += dstStride;
        src += srcStride;
    }
}
