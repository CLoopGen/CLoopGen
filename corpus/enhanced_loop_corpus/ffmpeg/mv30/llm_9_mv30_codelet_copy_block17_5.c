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
int stride_factor = dstStride > srcStride ? dstStride : srcStride;
for (i = 0; i < h * 2; i += 2) {
    // Unroll the loop: process two iterations per loop cycle
    if (i < h) {
        ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
        ((((union unaligned_64 *)((char *)(dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src) + 8))->l)));
        dst[16] = src[16];
    }

    if (i + 1 < h) {
        uint8_t *next_dst = dst + dstStride;
        uint8_t *next_src = src + srcStride;
        ((((union unaligned_64 *)(next_dst))->l) = ((((const union unaligned_64 *)(next_src))->l)));
        ((((union unaligned_64 *)((char *)(next_dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(next_src) + 8))->l)));
        next_dst[16] = next_src[16];
    }

    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
