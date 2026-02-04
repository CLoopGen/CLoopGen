#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t totalSrcOffset = 0;
    ptrdiff_t totalDstOffset = 0;
    for (i = 0; i < h; i++) {
        ptrdiff_t offset = i * 16;
        ((union unaligned_64 *)(dst + totalDstOffset + offset))->l = 
            ((const union unaligned_64 *)(src + totalSrcOffset + offset))->l;
        ((union unaligned_64 *)(dst + totalDstOffset + offset + 8))->l = 
            ((const union unaligned_64 *)(src + totalSrcOffset + offset + 8))->l;
    }
    // Update pointers once after loop (simulating batched access)
    dst += dstStride * h;
    src += srcStride * h;
}
