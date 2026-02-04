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
    for (i = 0; i < h; i++) {
        volatile union unaligned_32 *vdst = (volatile union unaligned_32 *)(dst);
        const union unaligned_32 *vsrc = (const union unaligned_32 *)(src);
        vdst->l = vsrc->l;
        dst += dstStride;
        src += srcStride;
        // Introduce artificial loop-carried dependency via compiler barrier
        // Ensures each iteration waits for the previous to complete (WAW dependency)
        asm volatile("" ::: "memory");
    }
}
