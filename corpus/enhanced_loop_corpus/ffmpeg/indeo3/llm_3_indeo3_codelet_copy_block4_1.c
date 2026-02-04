#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t offset = i * 4; // Assuming word-aligned access pattern with stride of 4 bytes
    uint8_t *d = dst + (h - 1 - i) * dstStride; // Reverse traversal in destination
    uint8_t *s = src + (h - 1 - i) * srcStride; // Corresponding reverse in source
    ((((union unaligned_32 *)(d + offset))->l) = ((((const union unaligned_32 *)(s + offset))->l)));
}
}
