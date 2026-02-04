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
    if (i + 1 < h) {
        ((union unaligned_64 *)(dst + i * dstStride))->l = ((const union unaligned_64 *)(src + i * srcStride))->l;
        ((union unaligned_64 *)(dst + (i + 1) * dstStride))->l = ((const union unaligned_64 *)(src + (i + 1) * srcStride))->l;
    } else {
        ((union unaligned_64 *)(dst + i * dstStride))->l = ((const union unaligned_64 *)(src + i * srcStride))->l;
    }
}
}
