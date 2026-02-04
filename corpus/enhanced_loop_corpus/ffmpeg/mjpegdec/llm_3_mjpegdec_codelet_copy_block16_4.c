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
ptrdiff_t total_dst_offset = 0;
ptrdiff_t total_src_offset = 0;
for (i = 0; i < h; i++) {
    ((union unaligned_64 *)(dst + total_dst_offset))->l = 
        ((const union unaligned_64 *)(src + total_src_offset))->l;
    ((union unaligned_64 *)(dst + total_dst_offset + 8))->l = 
        ((const union unaligned_64 *)(src + total_src_offset + 8))->l;
    total_dst_offset += dstStride;
    total_src_offset += srcStride;
}
}
