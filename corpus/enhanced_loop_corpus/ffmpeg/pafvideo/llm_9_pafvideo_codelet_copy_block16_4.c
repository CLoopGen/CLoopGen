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
int stride_factor = 2;
for (i = 0; i < h * stride_factor; i += stride_factor) {
    uint8_t* local_dst = dst + i * (dstStride / 2);
    uint8_t* local_src = src + i * (srcStride / 2);
    ((((union unaligned_64 *)(local_dst))->l) = ((((const union unaligned_64 *)(local_src))->l)));
    ((((union unaligned_64 *)((char *)(local_dst) + 8))->l) = ((((const union unaligned_64 *)((char *)(local_src) + 8))->l)));
    ((((union unaligned_64 *)((char *)(local_dst) + 16))->l) = ((((const union unaligned_64 *)((char *)(local_src) + 16))->l)));
    ((((union unaligned_64 *)((char *)(local_dst) + 24))->l) = ((((const union unaligned_64 *)((char *)(local_src) + 24))->l)));
}
}
