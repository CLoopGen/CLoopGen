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
uint64_t prev_dst_val = 0;
for (i = 0; i < h; i++) {
    uint64_t current_src_val = ((const union unaligned_64 *)(src))->l;
    (((union unaligned_64 *)(dst))->l) = current_src_val ^ prev_dst_val;
    (((union unaligned_64 *)((char *)(dst) + 8))->l) = ((const union unaligned_64 *)((const char *)(src) + 8))->l;
    dst[16] = src[16];
    prev_dst_val = current_src_val;
    dst += dstStride;
    src += srcStride;
}
}
