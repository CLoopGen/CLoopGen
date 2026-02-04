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
for (i = 0; i < h * 2; i++) {
    uint8_t *cur_dst = dst + (i / 2) * dstStride;
    uint8_t *cur_src = src + (i / 2) * srcStride;
    ((((union unaligned_64 *)(cur_dst))->l) = ((((const union unaligned_64 *)(cur_src))->l)));
    if (i % 2 == 0) {
        ((((union unaligned_64 *)((char *)(cur_dst) + 8))->l) = ((((const union unaligned_64 *)((char *)(cur_src) + 8))->l)));
    }
}
}
