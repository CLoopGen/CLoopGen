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
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        // Process two iterations at once with alternating access pattern
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        uint8_t *next_dst = dst + srcStride;
        uint8_t *next_src = src + dstStride;
        ((((union unaligned_32 *)(next_dst))->l) = ((((const union unaligned_32 *)(next_src))->l)));
    } else {
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
    }
    dst += dstStride * 2;
    src += srcStride * 2;
}
}
