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
int step = 2;
for (i = 0; i < h; i += step) {
    uint8_t *local_dst1 = dst;
    uint8_t *local_src1 = src;
    uint8_t *local_dst2 = dst + dstStride;
    uint8_t *local_src2 = src + srcStride;

    ((((union unaligned_64 *)(local_dst1))->l) = ((((const union unaligned_64 *)(local_src1))->l)));
    ((((union unaligned_64 *)((char *)(local_dst1) + 8))->l) = ((((const union unaligned_64 *)((const char *)(local_src1) + 8))->l)));
    local_dst1[16] = local_src1[16];

    if (i + 1 < h) {
        ((((union unaligned_64 *)(local_dst2))->l) = ((((const union unaligned_64 *)(local_src2))->l)));
        ((((union unaligned_64 *)((char *)(local_dst2) + 8))->l) = ((((const union unaligned_64 *)((const char *)(local_src2) + 8))->l)));
        local_dst2[16] = local_src2[16];
    }

    dst += dstStride * step;
    src += srcStride * step;
}
}
