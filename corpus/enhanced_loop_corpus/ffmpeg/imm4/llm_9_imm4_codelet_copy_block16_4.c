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
    int offset = (i % 2) * 8;
    uint8_t* current_dst = dst + (i / 2) * dstStride + offset;
    uint8_t* current_src = src + (i / 2) * srcStride + offset;
    ((((union unaligned_64 *)(current_dst))->l) = ((((const union unaligned_64 *)(current_src))->l)));
}
}
