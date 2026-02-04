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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < h; i++) {
        ((union unaligned_64 *)(local_dst))->l = ((const union unaligned_64 *)(local_src))->l;
        ((union unaligned_64 *)(local_dst + 8))->l = ((const union unaligned_64 *)(local_src + 8))->l;
        local_dst[16] = local_src[16];
        local_dst += dstStride;
        local_src += srcStride;
    }
    dst = local_dst;
    src = local_src;
}
