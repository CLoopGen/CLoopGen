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
    // Variant 2: Strided access pattern - simulate processing every other row by skipping in strides
    ptrdiff_t totalSrcOffset = 0;
    ptrdiff_t totalDstOffset = 0;

    for (i = 0; i < h; i++) {
        // Access memory with a fixed stride of 2 * original stride, simulating sparse copying
        uint8_t* currDst = dst + totalDstOffset;
        const uint8_t* currSrc = src + totalSrcOffset;

        ((uint64_t*)currDst)[0] = ((const uint64_t*)currSrc)[0];
        ((uint64_t*)currDst)[1] = ((const uint64_t*)currSrc)[1];
        currDst[16] = currSrc[16];

        totalDstOffset += dstStride;
        totalSrcOffset += srcStride;
    }
}
