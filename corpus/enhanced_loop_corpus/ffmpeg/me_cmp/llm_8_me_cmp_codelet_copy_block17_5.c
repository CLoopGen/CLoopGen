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
    for (i = 0; i < h; i += 2) {
        ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
        ((((union unaligned_64 *)((char *)(dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src) + 8))->l)));
        dst[16] = src[16];

        if (i + 1 < h) {
            uint8_t *dst_next = dst + dstStride;
            uint8_t *src_next = src + srcStride;

            ((((union unaligned_64 *)(dst_next))->l) = ((((const union unaligned_64 *)(src_next))->l)));
            ((((union unaligned_64 *)(dst_next + 8))->l) = ((((const union unaligned_64 *)(src_next + 8))->l)));
            dst_next[16] = src_next[16];
        }

        dst += 2 * dstStride;
        src += 2 * srcStride;
    }
}
