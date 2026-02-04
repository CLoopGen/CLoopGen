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
    uint8_t *temp_dst = dst;
    uint8_t *temp_src = src;
    ptrdiff_t offset = 0;
    for (i = 0; i < h; i++) {
        uint64_t val1 = ((const union unaligned_64 *)(temp_src + offset))->l;
        uint64_t val2 = ((const union unaligned_64 *)(temp_src + offset + 8))->l;
        ((union unaligned_64 *)(temp_dst + offset))->l = val1;
        ((union unaligned_64 *)(temp_dst + offset + 8))->l = val2;
        temp_dst[offset + 16] = temp_src[offset + 16];
        offset += dstStride;
    }
}
