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
    // Variant 1: Consecutive memory access with loop unrolling by 2
    // This changes the access pattern to process two iterations per loop step when possible,
    // reducing loop overhead and improving cache locality.

    int i;
    for (i = 0; i < h - 1; i += 2) {
        uint8_t *dst1 = dst;
        uint8_t *src1 = src;
        
        ((((union unaligned_32 *)(dst1))->l) = ((((const union unaligned_32 *)(src1))->l)));
        dst1 += dstStride;
        src1 += srcStride;
        
        ((((union unaligned_32 *)(dst1))->l) = ((((const union unaligned_32 *)(src1))->l)));
        
        dst += 2 * dstStride;
        src += 2 * srcStride;
    }
    
    // Handle remaining iteration if h is odd
    if (i < h) {
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
    }
}
