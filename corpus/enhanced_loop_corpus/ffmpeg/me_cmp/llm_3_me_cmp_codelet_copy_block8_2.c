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
ptrdiff_t totalDstOffset = 0;
ptrdiff_t totalSrcOffset = 0;
for (i = 0; i < h; i++) {
    ((union unaligned_64 *)(dst + totalDstOffset))->l = 
        ((const union unaligned_64 *)(src + totalSrcOffset))->l;
    totalDstOffset += dstStride;
    totalSrcOffset += srcStride;
}
}
