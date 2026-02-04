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
for (i = 0; i < h; i++) {
    int offset = (i & 3) * 9; // Small strided access pattern with modulo-induced stride
    ptrdiff_t effective_dst = offset % (dstStride > 0 ? dstStride : 8);
    ptrdiff_t effective_src = offset % (srcStride > 0 ? srcStride : 8);
    ((((union unaligned_64 *)(dst + effective_dst))->l) = ((((const union unaligned_64 *)(src + effective_src))->l)));
    dst[effective_dst + 8] = src[effective_src + 8];
    dst += dstStride;
    src += srcStride;
}
}
